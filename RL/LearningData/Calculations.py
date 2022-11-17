import pylab


def count_mem_usage(buffer_size, worker_amount, max_iteration_in_episode, target_episodes_amount):
    # all values are in MB
    default_server_usage = 1150
    default_client_usage = 20
    thousand_iteration_usage = 40
    thousand_iteration_after_buffer_fill_usage = 1.5
    usage_per_iteration = thousand_iteration_usage / 1000
    usage_per_iteration_after_buffer_fill = thousand_iteration_after_buffer_fill_usage / 1000
    system = 1000

    max_iteration_in_buffer = buffer_size
    max_episodes_in_buffer = max_iteration_in_buffer / max_iteration_in_episode

    worker_usage = (max_iteration_in_buffer * usage_per_iteration) + default_client_usage + default_server_usage
    all_workers_usage = worker_usage * worker_amount + system

    target_iterations_amount = target_episodes_amount * max_iteration_in_episode
    iterations_after_buffer_fill = target_iterations_amount - max_iteration_in_buffer

    worker_usage_to_reach_target_episodes = worker_usage + (iterations_after_buffer_fill * usage_per_iteration_after_buffer_fill)
    all_workers_usage_to_reach_target_episodes = (worker_usage_to_reach_target_episodes * worker_amount) + system

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
        episodes = 0
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

        #plt.figure()
        pylab.plot(x_values, epsilon_y_values)
        pylab.title("Przykłady funkcji rozkładu $\epsilon$")
        pylab.xlabel("Epizod (1 epizod = 100 iteracji)")
        pylab.ylabel("$\epsilon$")
        count += 1

    pylab.legend(labels)
    pylab.show()


    print("With epsilon_decay {} you need {} full episodes to reach epsilon_min in mode {}".format(epsilon_decay,
                                                                                                   episodes,
                                                                                                   mode))


if __name__ == "__main__":
    count_mem_usage(buffer_size=75_000, worker_amount=5, max_iteration_in_episode=200, target_episodes_amount=5000)
    eps = [0.99953, 0.0001]
    mode = ["exp", "linear"]
    #count_episodes_to_reach_eps_min(epsilon_decay=eps, max_steps_per_episode=100, mode=mode)

    # eps = [1e-6]
    # for e in eps:
    #     count_episodes_to_reach_eps_min(epsilon_decay=e, mode="linear")

