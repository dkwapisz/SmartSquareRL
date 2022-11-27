##############################################################################
import math

# import packages

##############################################################################


import numpy as np

import heapq

import matplotlib.pyplot as plt

from matplotlib.pyplot import figure


##############################################################################

# heuristic function for path scoring

##############################################################################


def heuristic(a, b):
    return np.sqrt((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2)


##############################################################################

# path finding function

##############################################################################


def astar(array, start, goal):
    neighbors = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    close_set = set()

    came_from = {}

    gscore = {start: 0}

    fscore = {start: heuristic(start, goal)}

    oheap = []

    heapq.heappush(oheap, (fscore[start], start))

    while oheap:

        current = heapq.heappop(oheap)[1]

        if current == goal:

            data = []

            while current in came_from:
                data.append(current)

                current = came_from[current]

            return data

        close_set.add(current)

        for i, j in neighbors:

            neighbor = current[0] + i, current[1] + j

            tentative_g_score = gscore[current] + heuristic(current, neighbor)

            if 0 <= neighbor[0] < array.shape[0]:

                if 0 <= neighbor[1] < array.shape[1]:

                    if array[neighbor[0]][neighbor[1]] == 1:
                        continue

                else:

                    # array bound y walls

                    continue

            else:

                # array bound x walls

                continue

            if neighbor in close_set and tentative_g_score >= gscore.get(neighbor, 0):
                continue

            if tentative_g_score < gscore.get(neighbor, 0) or neighbor not in [i[1] for i in oheap]:
                came_from[neighbor] = current

                gscore[neighbor] = tentative_g_score

                fscore[neighbor] = tentative_g_score + heuristic(neighbor, goal)

                heapq.heappush(oheap, (fscore[neighbor], neighbor))

    return False


def create_action_list(root):
    actions = []
    for coord in range(0, len(root) - 1, 1):
        if root[coord][0] > root[coord + 1][0]:
            actions.append("UP")
        if root[coord][0] < root[coord + 1][0]:
            actions.append("DOWN")
        if root[coord][1] > root[coord + 1][1]:
            actions.append("LEFT")
        if root[coord][1] < root[coord + 1][1]:
            actions.append("RIGHT")
    return actions


def calculate_path(grid, finish):

    coins = np.argwhere(grid == 4).tolist()
    whole_root = []

    max_i = 2 # coins

    if finish:
        max_i = 1

    for i in range(0, max_i, 1):
        if i == 0:
            start = tuple(np.argwhere(grid == 8).tolist()[0])
        else:
            start = tuple(distance[sorted(distance.keys())[0]])
            coins.remove(list(distance[sorted(distance.keys())[0]]))
            distance.pop(sorted(distance.keys())[0])

        distance = {}

        for coin in coins:
            dist = math.sqrt(math.hypot((coin[0] - start[0]), (coin[1] - start[1])))
            distance[dist] = coin

        goal = tuple(distance[sorted(distance.keys())[0]])

        route = astar(grid, start, goal)

        if i == 0:
            route = route + [start]

        route = route[::-1]

        whole_root += route
    #
    # print(create_action_list(whole_root))
    # print(len(create_action_list(whole_root)))
    #
    # print("Route len: {}".format(len(whole_root)))
    # print("Whole root: {}".format(whole_root))

    return create_action_list(whole_root)

##############################################################################

# plot the path

##############################################################################


# extract x and y coordinates from route list

    # x_coords = []
    #
    # y_coords = []
    #
    # for i in (range(0, len(whole_root))):
    #     x = whole_root[i][0]
    #
    #     y = whole_root[i][1]
    #
    #     x_coords.append(x)
    #
    #     y_coords.append(y)
    #
    # # plot map and path
    #
    # fig, ax = plt.subplots(figsize=(20, 20))
    #
    # ax.imshow(grid, cmap=plt.cm.Dark2)
    #
    # ax.scatter(start[1], start[0], marker="*", color="yellow", s=200)
    #
    # ax.scatter(goal[1], goal[0], marker="*", color="red", s=200)
    #
    # ax.plot(y_coords, x_coords, color="black")
    #
    # plt.show()