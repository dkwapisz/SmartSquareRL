import pylab
import numpy as np

multiple_x = []
multiple_y = []
multiple_z = []
tested_param = {}

nr_of_workers = 5

for i in range(0, nr_of_workers, 1):
    with open("./reward_worker_{}.logs".format(i), "r") as file:
        line = file.read().splitlines()[0].split(" ")
        tested_param[line[6]] = line[3]

for i in range(0, nr_of_workers, 1):
    with open("./reward_worker_{}.logs".format(i), "r") as file:
        x = []
        y = []
        z = []
        for line in file.readlines():
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

nr_of_plots = 5

tested_parameter = list(tested_param.values())[0]

for j in range(0, nr_of_workers, nr_of_plots):
    pylab.figure(dpi=800, figsize=[12, 4])
    #pylab.title("Worker {}".format(j))
    pylab.xticks([i for i in range(0, 10000, 1000)])
    pylab.yticks([i for i in range(-4000, 1200, 400)])
    pylab.xlabel("Episode")
    pylab.ylabel("Reward")
    print(j, j+nr_of_plots)
    print(list(tested_param.keys()))
    for i in range(j, j+nr_of_plots, 1):
        plot = pylab.plot(multiple_x[i], multiple_y[i], linewidth=0.5, label="worker{}".format(i))
    pylab.legend(loc='lower right')

    pylab.savefig("wykres1.png")
    #pylab.show()

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
