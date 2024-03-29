# Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
# License:      GPLv3

import pylab
import numpy as np

multiple_x = []
multiple_y = []
multiple_z = []
wins = []
tested_param = {}
all_cases = []

nr_of_workers = 1

for i in range(0, nr_of_workers, 1):
    i = 6
    with open("./reward_worker_{}.logs".format(i), "r") as file:
        line = file.read().splitlines()[0].split(" ")
        tested_param[line[6]] = line[3]

for i in range(0, nr_of_workers, 1):
    i = 6
    with open("./reward_worker_{}.logs".format(i), "r") as file:
        x = []
        y = []
        z = []
        win = 0
        for line in file.readlines()[1:]:
            # print(line.split(" ")) [1] -> reward, [3] -> episode, [6] -> coinsLeft, [8] -> epsilon
            split = line.split(" ")
            reward = split[1][:-1]
            episode = split[3][:-1]
            coins_left = split[6][:-1]
            #print(split[-1])
            if "[WIN]" in split[-1]:
                win += 1
            all_cases.append(split[-1])
            #print("Episode: {}, Reward: {}".format(episode, reward))
            x.append(episode)
            y.append(int(reward))
            z.append(int(coins_left))

        multiple_x.append(x)
        multiple_y.append(y)
        multiple_z.append(z)
        wins.append(win)

nr_of_plots = 1

print(wins)

tested_parameter = list(tested_param.values())[0]

for j in range(0, nr_of_workers, nr_of_plots):
    pylab.figure(dpi=800, figsize=[16, 4])
    #pylab.title("Worker {}".format(j))
    pylab.xticks([i for i in range(0, 10000, 1000)])
    pylab.yticks([i for i in range(-3000, 1200, 200)])
    pylab.xlabel("Episode")
    pylab.ylabel("Reward")
    #print(j, j+nr_of_plots)
    #print(list(tested_param.keys()))
    for i in range(j, j+nr_of_plots, 1):
        plot = pylab.plot(multiple_x[i], multiple_y[i], linewidth=0.5, label="worker{}".format(j))
    pylab.legend(loc='lower right')

    #pylab.savefig("wykres1.png")
    #pylab.show()

for i in range(0, 8400, 100):
    count = 0
    for j in range(0, 100, 1):
        if "[WIN]" in all_cases[i+j]:
            count += 1
    print("Maps: {} - {}, wins: {}".format(i, i+100, count))

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
