import numpy as np
import tensorflow as tf
from keras import Sequential
from keras.layers import Dense
from keras import backend as keras_back
from keras.optimizers import Adam
from tensorflow.keras.models import load_model
from tensorflow.keras.losses import Huber

MEM_SIZE = 100_000
BATCH_SIZE = 128


class Memory:

    def __init__(self, input_dims, action_dims):
        self.state_memory = np.zeros((MEM_SIZE, input_dims))
        self.new_state_memory = np.zeros((MEM_SIZE, input_dims))
        self.action_memory = np.zeros((MEM_SIZE, action_dims), dtype=np.int8)
        self.reward_memory = np.zeros(MEM_SIZE)
        self.terminal_memory = np.zeros(MEM_SIZE, dtype=np.int32)
        self.memory_index = 0

    def write_to_memory(self, state, action, reward, new_state, done):
        index = self.memory_index % MEM_SIZE
        self.state_memory[index] = state
        self.new_state_memory[index] = new_state
        self.reward_memory[index] = reward

        actions = np.zeros(self.action_memory.shape[1])
        actions[action] = 1.0
        self.action_memory[index] = actions

        self.terminal_memory[index] = 1 - int(done)
        self.memory_index += 1

    def get_sample_batch(self):
        max_mem = min(self.memory_index, MEM_SIZE)
        batch = np.random.choice(max_mem, BATCH_SIZE, replace=False)
        states = self.state_memory[batch]
        new_state = self.new_state_memory[batch]
        rewards = self.reward_memory[batch]
        actions = self.action_memory[batch]
        terminal = self.terminal_memory[batch]

        return states, actions, rewards, new_state, terminal


def build_dqn(lr, action_dims):
    model = Sequential()
    model.add(Dense(256, activation='relu'))
    model.add(Dense(256, activation='relu'))
    model.add(Dense(action_dims))
    model.compile(optimizer=Adam(learning_rate=lr), loss=Huber(delta=1.35))

    return model


class DoubleDQN:
    def __init__(self, lr, gamma, action_dims, input_dims, eps, eps_decay=5e-4, eps_min=0.05, replace_target=100):
        self.action_space = [i for i in range(action_dims)]
        self.gamma = gamma
        self.epsilon = eps
        self.epsilon_decay = eps_decay
        self.epsilon_min = eps_min
        self.replace_target = replace_target
        self.memory = Memory(input_dims, action_dims)
        self.neural_network_eval = build_dqn(lr, action_dims)
        self.neural_network_target = build_dqn(lr, action_dims)

    def save_neural_network(self):
        self.neural_network_eval.save("Double_DQN_1.h5")

    def load_neural_network(self):
        self.neural_network_eval = load_model("Double_DQN_1.h5")
        if self.epsilon == 0.0:
            self.neural_network_target.set_weights(self.neural_network_eval.get_weights())

    def write_to_memory(self, state, action, reward, new_state, done):
        self.memory.write_to_memory(state, action, reward, new_state, done)

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
            q_target = q_pred

            batch_index = np.arange(BATCH_SIZE, dtype=np.int32)
            q_target[batch_index, action_indices] = reward + self.gamma * q_next[batch_index, max_actions.astype(int) * done]

            _ = self.neural_network_eval.fit(state, q_target, verbose=0)

            if self.epsilon > self.epsilon_min:
                self.epsilon -= self.epsilon_decay
            else:
                self.epsilon = self.epsilon_min

            print("Epsilon: {}".format(self.epsilon))

            if self.memory.memory_index % self.replace_target == 0:
                self.neural_network_target.set_weights(self.neural_network_eval.get_weights())

