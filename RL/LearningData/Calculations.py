import numpy as np
import pylab


class Buffer:

    def __init__(self, buffer_size, map_size, one_hot_encoding_size):
        self.state_buffer = np.zeros((buffer_size, map_size, map_size, one_hot_encoding_size), dtype=np.int8)
        self.new_state_buffer = np.zeros((buffer_size, map_size, map_size, one_hot_encoding_size), dtype=np.int8)
        self.action_buffer = np.zeros((buffer_size, 4), dtype=np.int8)
        self.reward_buffer = np.zeros(buffer_size, dtype=np.int16)
        self.terminal_buffer = np.zeros(buffer_size, dtype=np.int32)

    def calculate_usage(self):
        return (self.state_buffer.nbytes +
                self.new_state_buffer.nbytes +
                self.action_buffer.nbytes +
                self.reward_buffer.nbytes +
                self.terminal_buffer.nbytes) / (1024 ** 2)


def count_mem_usage(buffer_size, map_size, one_hot_encoding_size, worker_amount, max_iteration_in_episode):
    buffer = Buffer(buffer_size, map_size, one_hot_encoding_size)
    # all values are in MB
    default_server_usage = 1200
    default_client_usage = 20
    thousand_iteration_usage = buffer.calculate_usage()
    print(buffer.calculate_usage())
    usage_per_iteration = thousand_iteration_usage / 1000
    system = 1000

    max_iteration_in_buffer = buffer_size
    max_episodes_in_buffer = max_iteration_in_buffer / max_iteration_in_episode

    worker_usage = (max_iteration_in_buffer * usage_per_iteration) + default_client_usage + default_server_usage
    all_workers_usage = worker_usage * worker_amount + system

    print("----------------------------------------------------------------------------------------")
    print("With {} workers and {} buffer_size:".format(worker_amount, buffer_size))
    print("  -> single worker will use {} MB memory (excluding system usage).".format(int(worker_usage)))
    print("  -> all workers will use {} MB memory (including system usage).".format(int(all_workers_usage)))
    print("  -> buffer can hold approximately: {} episodes.".format(int(max_episodes_in_buffer)))
    print("----------------------------------------------------------------------------------------")


def count_episodes_to_reach_eps_min(epsilon_decay, max_steps_per_episode, mode):
    episodes = 0
    count = 0
    labels = []
    for m in mode:
        x_values = []
        epsilon_y_values = []
        epsilon = 1.0
        epsilon_min = 0.01
        steps = 0
        if m == "exp":
            labels.append("$\epsilon$ = $\epsilon$ - 0.0001x")
        elif m == "linear":
            labels.append("$\epsilon$ = $\epsilon$ $\cdot$  $0.99953^x$")

        while epsilon > epsilon_min:
            if m == "exp":
                epsilon *= epsilon_decay[count]
            elif m == "linear":
                epsilon -= epsilon_decay[count]

            steps += 1

            x_values.append(steps)
            epsilon_y_values.append(epsilon)

        episodes = steps / max_steps_per_episode

        x_values = [x / max_steps_per_episode for x in x_values]

        # plt.figure()
        pylab.plot(x_values, epsilon_y_values)
        pylab.xlabel("Episodes")
        pylab.ylabel("$\epsilon$")
        count += 1

    pylab.legend(labels)
    pylab.show()

    print("With epsilon_decay {} you need {} full episodes to reach epsilon_min in mode {}".format(epsilon_decay,
                                                                                                   episodes,
                                                                                                   mode))


if __name__ == "__main__":
    count_mem_usage(buffer_size=1_000, map_size=20, one_hot_encoding_size=5, worker_amount=5, max_iteration_in_episode=200)
    eps = [0.999995]
    mode = ["exp"]
    count_episodes_to_reach_eps_min(epsilon_decay=eps, max_steps_per_episode=200, mode=mode)
