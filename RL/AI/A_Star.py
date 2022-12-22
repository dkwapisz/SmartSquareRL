# This code is modified version of: https://www.analytics-link.com/post/2018/09/14/applying-the-a-path-finding-algorithm-in-python-part-1-2d-square-grid

import math
import numpy as np
import heapq


def heuristic(a, b):
    return np.sqrt((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2)


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
                    continue

            else:
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


def calculate_path(grid, finish, coins_amount):
    coins = np.argwhere(grid == 4).tolist()
    whole_root = []

    if finish:
        coins_amount = 1

    for i in range(0, coins_amount, 1):
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

    return create_action_list(whole_root)

