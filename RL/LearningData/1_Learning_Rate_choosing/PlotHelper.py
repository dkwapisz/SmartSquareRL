import sys

import pylab
import numpy as np

####################### INPUT PARAMETERS ##########################

tested_parameter = [0.01, 0.003, 0.001, 0.0003, 0.0001, "0.00003"]
episodes_limit = 2000
coins_in_level = 5
nr_of_workers = 5

###################################################################


def average_list(data, average):
    averaged_list = [[], [], [], [], [], []]
    x_averaged_list = []

    for i in range(0, nr_of_workers, 1):
        x_averaged_list.append([x for x in range(0, episodes_limit, average)])

    for i in range(0, nr_of_workers, 1):
        value = 0
        for k in range(0, len(data[i]), 1):
            value += data[i][k]
            if k % average == 0 and k != 0:
                value /= average
                averaged_list[i].append(value)
                value = 0
        value /= average
        averaged_list[i].append(value)

    return x_averaged_list, averaged_list

multiple_x = []
multiple_y = []
multiple_z = []
wins = []
collectedCoins = []
tested_param = {}
sum_reward_per_coins = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, "WIN": 0}
number_of_cases_coins_collected = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, "WIN": 0}
average_reward_per_coins = {0: 0, 1: 0, 2: 0, 3: 0, 4: 0, 5: 0, "WIN": 0}
base_reward_by_collected_coins = {0: -925, 1: -725, 2: -525, 3: -325, 4: -125, 5: -125, "WIN": 875}

for i in range(1, nr_of_workers+1, 1):
    with open("./reward_worker_{}.logs".format(i), "r") as file:
        line = file.read().splitlines()[0].split(" ")
        tested_param[line[6]] = line[3]

for i in range(1, nr_of_workers+1, 1):
    with open("./reward_worker_{}.logs".format(i), "r") as file:
        x = []
        y = []
        z = []
        win = 0
        coin = 0
        for line in file.readlines()[1:]:
            # print(line.split(" ")) [1] -> reward, [3] -> episode, [6] -> coinsLeft, [8] -> epsilon
            split = line.split(" ")
            reward = split[1][:-1]
            episode = split[3][:-1]
            coins_left = split[6][:-1]
            coins_collected = 5 - int(split[6][0])
            if "[WIN]" in split[-1]:
                win += 1
                sum_reward_per_coins["WIN"] += int(reward)
                number_of_cases_coins_collected["WIN"] += 1
            else:
                sum_reward_per_coins[coins_collected] += int(reward)
                number_of_cases_coins_collected[coins_collected] += 1
            coin += coins_collected
            x.append(episode)
            y.append(int(reward))
            z.append(5 - int(coins_left))

        multiple_x.append(x)
        multiple_y.append(y)
        multiple_z.append(z)
        wins.append(win)
        collectedCoins.append(coin)

nr_of_plots = 5

print("Wins: {}".format(wins))
print("Collected coins in all episodes: {}".format(collectedCoins))
print("Average coins in episode: {}".format(list(c/len(x) for c in collectedCoins)))
print("Number of cases coins in episode: {}".format(number_of_cases_coins_collected))
for i in range(1, 7):
    if (list(number_of_cases_coins_collected.values())[i]) != 0:
        average_reward = (list(sum_reward_per_coins.values())[i]) / (list(number_of_cases_coins_collected.values())[i])
    else:
        average_reward = 0
    print("If collected {} coins, average reward is: {}".format(list(sum_reward_per_coins.keys())[i], average_reward))
    if i > coins_in_level:
        average_reward_per_coins["WIN"] = average_reward
    else:
        average_reward_per_coins[i] = average_reward

x_averaged_list, averaged_list = average_list(multiple_y, 2)

print(averaged_list)

#sys.exit()

for j in range(0, nr_of_workers, nr_of_plots):
    pylab.figure(dpi=600, figsize=[10, 6])
    #pylab.xticks([i for i in range(-0, 100, 10)])
    #pylab.yticks([i for i in range(-3600, 0, 200)])
    #pylab.ylim(-3600, 0)
    pylab.xlabel("Epizody")
    pylab.ylabel("Nagroda")
    for avg_rew in average_reward_per_coins.values():
        if avg_rew != 0:
            pylab.axhline(avg_rew, linestyle="--", linewidth=0.7, color="k")
    for i in range(j, j+nr_of_plots, 1):
        plot = pylab.plot(x_averaged_list[i], averaged_list[i], linewidth=0.9, label=r"$\alpha$ = " + str(tested_parameter[i+1]))
    pylab.legend(loc='lower right')

    pylab.savefig("wykresLR.png")
    pylab.show()

# for j in range(0, nr_of_workers, nr_of_plots):
#     pylab.figure(dpi=600, figsize=[10, 6])
#     # pylab.title("Wykres przedstawiający osiągniętą nagrodę w kolejnych epizodach")
#     pylab.xticks([i for i in range(0, 2000, 200)])
#     pylab.yticks([i for i in range(0, 6, 1)])
#     pylab.xlabel("Epizody")
#     pylab.ylabel("Nagroda")
#     for i in range(j, j+nr_of_plots, 1):
#         pylab.plot(multiple_x[i], multiple_z[i], linewidth=0.4, label="worker{}".format(i))
#     pylab.legend(loc='lower right')
#
#     pylab.show()



