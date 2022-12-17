import matplotlib.pyplot as plt

x = [i for i in range(0, 10000, 1)]
epsilon = []
wins = []
win = 0

with open("./reward_worker_{}.logs".format(3), "r") as file:
    for line in file.readlines():
        # print(line.split(" ")) [1] -> reward, [3] -> episode, [6] -> coinsLeft, [8] -> epsilon
        split = line.split(" ")
        epsilon.append(float(split[8][:-1]))

        if "[WIN]" in split[-1]:
            win += 1
        wins.append(win)


fig, ax1 = plt.subplots(dpi=600)

ax2 = ax1.twinx()
ax1.plot(x, wins, 'g-')
ax2.plot(x, epsilon, 'b-')

ax1.set_xlabel('Epizody')
ax1.set_ylabel('Liczba wygranych', color='g')
ax2.set_ylabel('Epsilon', color='b')

plt.show()