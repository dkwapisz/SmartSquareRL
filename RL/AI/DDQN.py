import json
import psutil
import numpy as np
import tensorflow as tf
from keras import Sequential
from keras.layers import Dense
from keras.optimizers import Adam
from tensorflow.keras.models import load_model
from tensorflow.keras.losses import Huber
import os

global MEM_SIZE
global BATCH_SIZE
global ACTIONS


def get_param(param_name, worker_id):
    with open("../LearningData/learning_params.json") as paramsFile:
        params = json.load(paramsFile)

    if len(params[param_name]) == 1:
        return params[param_name][0]
    else:
        return params[param_name][worker_id]

class Memory:
    def __init__(self, input_dims, action_dims, worker_id):
        global MEM_SIZE, BATCH_SIZE, ACTIONS
        MEM_SIZE = get_param("mem_size", worker_id)
        BATCH_SIZE = get_param("batch_size", worker_id)

        self.state_memory = np.zeros((MEM_SIZE, input_dims))
        self.new_state_memory = np.zeros((MEM_SIZE, input_dims))
        self.action_memory = np.zeros((MEM_SIZE, action_dims), dtype=np.int8)
        self.reward_memory = np.zeros(MEM_SIZE)
        self.terminal_memory = np.zeros(MEM_SIZE, dtype=np.int32)
        self.memory_index = 0

        ACTIONS = self.get_init_actions(action_dims)

    def write_to_memory(self, state, action, reward, new_state, done):
        index = self.memory_index % MEM_SIZE
        # if index == 0:
        #     print("MEMORY INDEX IS 0. RAM USAGE: {} MB".format(psutil.Process(os.getpid()).memory_info().rss / 1024 ** 2))
        # if index != 0 and index % 500 == 0:
        #     print("MEMORY BUFFER HITS {}. RAM USAGE: {}".format(index, psutil.Process(os.getpid()).memory_info().rss / 1024 ** 2))
        self.state_memory[index] = state
        self.new_state_memory[index] = new_state
        self.reward_memory[index] = reward

        # actions = np.zeros(self.action_memory.shape[1])
        # actions[action] = 1.0
        self.action_memory[index] = ACTIONS[action]

        self.terminal_memory[index] = 1 - int(done)
        self.memory_index += 1

    def get_init_actions(self, action_dims):
        for i in range(0, action_dims, 1):
            ACTIONS[i] = np.zeros(self.action_memory.shape[1])
            ACTIONS[i][i] = 1.0
        return ACTIONS

    def get_sample_batch(self):
        max_mem = min(self.memory_index, MEM_SIZE)
        batch = np.random.choice(max_mem, BATCH_SIZE, replace=False)
        states = self.state_memory[batch]
        new_state = self.new_state_memory[batch]
        rewards = self.reward_memory[batch]
        actions = self.action_memory[batch]
        terminal = self.terminal_memory[batch]

        return states, actions, rewards, new_state, terminal


def set_tf_gpu():
    os.environ['TF_XLA_FLAGS'] = '--tf_xla_enable_xla_devices'
    os.environ['CUDA_VISIBLE_DEVICES'] = "0"
    gpu_devices = tf.config.experimental.list_physical_devices('GPU')
    for device in gpu_devices:
        tf.config.experimental.set_memory_growth(device, True)
    print("Num GPUs Available: ", len(tf.config.list_physical_devices('GPU')))


def build_dqn(worker_id, action_dims):
    set_tf_gpu()

    lr = get_param("learning_rate", worker_id)
    huber_delta = get_param("huber_delta", worker_id)
    layers = get_param("network_layers", worker_id)
    neurons = get_param("neurons", worker_id)

    model = Sequential()

    for i in range(0, layers):
        model.add(
            Dense(neurons[i],
                  activation='relu',
                  kernel_initializer=tf.keras.initializers.VarianceScaling(scale=2.0,
                                                                           mode='fan_in',
                                                                           distribution='truncated_normal'))
        )
    model.add(Dense(action_dims,
                    activation='softmax',
                    kernel_initializer=tf.keras.initializers.RandomUniform(minval=-0.03, maxval=0.03),
                    bias_initializer=tf.keras.initializers.Constant(-0.2)))

    model.compile(optimizer=Adam(learning_rate=lr), loss=Huber(delta=huber_delta))
    return model


class DoubleDQN:
    def __init__(self, action_dims, input_dims, worker_id):
        self.action_space = [i for i in range(action_dims)]
        self.gamma = get_param("gamma", worker_id)
        self.epsilon = get_param("epsilon", worker_id)
        self.epsilon_decay = get_param("epsilon_decay", worker_id)
        self.epsilon_min = get_param("epsilon_min", worker_id)
        self.replace_target = get_param("replace_target", worker_id)
        self.memory = Memory(input_dims, action_dims, worker_id)
        self.neural_network_eval = build_dqn(worker_id, action_dims)
        self.neural_network_target = build_dqn(worker_id, action_dims)

    def save_neural_network(self, episodeCount, worker_id):
        eval_network = "../LearningData/NeuralNetworks/Worker{}/DDQN_eval_episode_{}_worker_{}.h5".format(worker_id,
                                                                                                          episodeCount,
                                                                                                          worker_id)
        target_network = "../LearningData/NeuralNetworks/Worker{}/DDQN_target_episode_{}_worker_{}.h5".format(worker_id,
                                                                                                              episodeCount,
                                                                                                              worker_id)
        self.neural_network_eval.save(eval_network)
        self.neural_network_eval.save(target_network)

    def load_neural_network(self):
        self.neural_network_eval = load_model("DDQN_episode_0.h5")
        self.neural_network_target.set_weights(self.neural_network_eval.get_weights())

    def write_to_memory(self, state, action, reward, new_state, done):
        self.memory.write_to_memory(state, action, reward, new_state, done)

    def get_epsilon(self):
        return self.epsilon

    def calculate_action(self, state):
        state = np.array(state)
        state = state[np.newaxis, :]

        rand = np.random.random()
        if rand < self.epsilon:
            action = np.random.choice(self.action_space)
        else:
            actions = self.neural_network_eval.predict(state)
            action = np.argmax(actions)

        return action

    def learn(self):
        if self.memory.memory_index > BATCH_SIZE:
            state, action, reward, new_state, done = self.memory.get_sample_batch()
            action_values = np.array(self.action_space, dtype=np.int8)
            action_indices = np.dot(action, action_values)
            q_next = self.neural_network_target.predict(new_state)
            q_eval = self.neural_network_eval.predict(new_state)
            q_pred = self.neural_network_eval.predict(state)

            max_actions = np.argmax(q_eval, axis=1)

            batch_index = np.arange(BATCH_SIZE, dtype=np.int32)
            q_pred[batch_index, action_indices] = reward + self.gamma * q_next[
                batch_index, max_actions.astype(int) * done]

            self.neural_network_eval.fit(state, q_pred, verbose=0)

            # if self.epsilon > self.epsilon_min:
            #     self.epsilon -= self.epsilon_decay
            # else:
            #     self.epsilon = self.epsilon_min

            self.epsilon = self.epsilon * self.epsilon_decay if self.epsilon > self.epsilon_min else self.epsilon_min

            if self.memory.memory_index % self.replace_target == 0:
                self.neural_network_target.set_weights(self.neural_network_eval.get_weights())
