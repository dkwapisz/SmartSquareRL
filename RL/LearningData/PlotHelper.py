import pylab
import numpy as np

multiple_x = []
multiple_y = []

nr_of_workers = 8

for i in range(0, nr_of_workers, 1):
    with open("reward_worker_{}.logs".format(i), "r") as file:
        x = []
        y = []
        for line in file.readlines()[1:]:
            # print(line.split(" ")) [1] -> reward, [3] -> episode, [6] -> coinsLeft, [8] -> epsilon
            splitted = line.split(" ")
            reward = splitted[1][:-1]
            episode = splitted[3][:-1]
            print("Episode: {}, Reward: {}".format(episode, reward))
            x.append(episode)
            y.append(int(reward))

        multiple_x.append(x)
        multiple_y.append(y)

nr_of_plots = 8

for j in range(0, nr_of_workers, nr_of_plots):
    pylab.figure(dpi=600)
    pylab.xticks([i for i in range(0, 500, 50)])
    pylab.yticks([i for i in range(-2000, 0, 100)])
    print(j, j+nr_of_plots)
    for i in range(j, j+nr_of_plots, 1):
        pylab.plot(multiple_x[i], multiple_y[i], linewidth=0.4, label="worker{}".format(i))
    pylab.legend(loc='lower right')

    pylab.show()