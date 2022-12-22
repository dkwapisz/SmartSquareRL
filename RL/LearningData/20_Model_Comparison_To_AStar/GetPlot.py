# Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
# License:      GPLv3

import pylab

name = "20x20"
y_values_count = 0
y_values_RL = []
y_values_AStar = []

sum_RL = 0
sum_AStar = 0

with open("{}Logs_RL.txt".format(name), "r") as file_RL:
    with open("{}Logs_AStar.txt".format(name), "r") as file_AStar:

        lines_RL = file_RL.readlines()
        lines_AStar = file_AStar.readlines()

        for i in range(0, 1000, 1):
            line_RL = lines_RL[i]
            line_AStar = lines_AStar[i]

            if "[WIN]" in line_RL.split(" ")[8]:
                y_values_RL.append(int(line_RL.split(" ")[7]))
                y_values_AStar.append(int(line_AStar.split(" ")[7]))
                y_values_count += 1
                sum_RL += int(line_RL.split(" ")[7])
                sum_AStar += int(line_AStar.split(" ")[7])

print("RL needs: {} iterations".format(sum_RL))
print("AStar needs: {} iterations".format(sum_AStar))

diff = []
RL_better = 0
AStar_better = 0
same_result = 0

for i in range(0, y_values_count, 1):
    difference = y_values_RL[i] - y_values_AStar[i]

    if difference > 0:
        AStar_better += 1
    elif difference < 0:
        RL_better += 1
    else:
        same_result += 1

    diff.append(difference)

print("RL was better: {}, A* was better: {}, same results: {}".format(RL_better, AStar_better, same_result))

# pylab.figure(dpi=600, figsize=[8, 4])
# #pylab.title("Worker {}".format(j))
# pylab.xticks([i for i in range(0, 679, 50)])
# pylab.yticks([i for i in range(30, 100, 5)])
# # pylab.xlabel("Episode")
# # pylab.ylabel("Reward")
# #print(j, j+nr_of_plots)
# #print(list(tested_param.keys()))
# plot = pylab.plot([i for i in range(0, y_values_count, 1)], y_values_RL, linewidth=0.5, label="RL")
# plot = pylab.plot([i for i in range(0, y_values_count, 1)], y_values_AStar, linewidth=0.5, label="A*")
# pylab.legend(loc='lower right')
# pylab.show()

pylab.figure(dpi=600, figsize=[8, 4])
pylab.title("Plansze 20x20")
pylab.xticks([i for i in range(0, y_values_count, 50)])
pylab.yticks([i for i in range(-50, 50, 5)])
pylab.xlabel("Nr planszy")
pylab.ylabel("Przewaga iteracji")
#print(j, j+nr_of_plots)
#print(list(tested_param.keys()))
plot = pylab.plot([i for i in range(0, y_values_count, 1)], diff, linewidth=0.5, label="Różnica iteracji (RL - A*)")
pylab.legend(loc='lower right')
pylab.show()