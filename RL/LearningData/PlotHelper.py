import pylab
import numpy as np

multiple_x = []
multiple_y = []
multiple_z = []

nr_of_workers = 6

for i in range(0, nr_of_workers, 1):
    with open("4_Iteration_per_episode_choosing2/reward_worker_{}.logs".format(i), "r") as file:
        x = []
        y = []
        z = []
        for line in file.readlines()[1:]:
            # print(line.split(" ")) [1] -> reward, [3] -> episode, [6] -> coinsLeft, [8] -> epsilon
            split = line.split(" ")
            reward = split[1][:-1]
            episode = split[3][:-1]
            coins_left = split[6][:-1]
            print("Episode: {}, Reward: {}".format(episode, reward))
            x.append(episode)
            y.append(int(reward))
            z.append(int(coins_left))

        multiple_x.append(x)
        multiple_y.append(y)
        multiple_z.append(z)

nr_of_plots = 6

for j in range(0, nr_of_workers, nr_of_plots):
    pylab.figure(dpi=800, figsize=[8, 4])
    pylab.title("Batch_size")
    pylab.xticks([i for i in range(0, 2000, 200)])
    pylab.yticks([i for i in range(-3000, 500, 200)])
    print(j, j+nr_of_plots)
    for i in range(j, j+nr_of_plots, 1):
        pylab.plot(multiple_x[i], multiple_y[i], linewidth=0.5, label="worker{}".format(i))
    pylab.legend(loc='lower right')

    pylab.show()

# for j in range(0, nr_of_workers, nr_of_plots):
#     pylab.figure(dpi=600)
#     pylab.title("Coins_left")
#     pylab.xticks([i for i in range(0, 2000, 200)])
#     pylab.yticks([i for i in range(0, 5, 200)])
#     print(j, j+nr_of_plots)
#     for i in range(j, j+nr_of_plots, 1):
#         pylab.plot(multiple_x[i], multiple_z[i], linewidth=0.4, label="worker{}".format(i))
#     pylab.legend(loc='lower right')
#
#     pylab.show()
