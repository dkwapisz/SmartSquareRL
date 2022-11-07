import random

mapping = {
    "floor": 0,
    "wall": 1,
    "coin": 4,
    "finish": 7,
    "player": 8
}


def create_map_with_border(map_size):
    map_ = [[0 for _ in range(0, map_size, 1)] for _ in range(0, map_size, 1)]
    for i in range(0, map_size, 1):
        for j in range(0, map_size, 1):
            if any([i == 0, i == map_size - 1, j == 0, j == map_size - 1]):
                map_[i][j] = mapping["wall"]
            else:
                map_[i][j] = mapping["floor"]
    return map_


def generate_maps(map_size):
    game_map = create_map_with_border(map_size)

    min_coins = 2
    max_coins = 2

    min_walls = 1
    max_walls = 2

    min_wall_height = 1
    max_wall_height = 1

    min_wall_width = 1
    max_wall_width = 1

    # finish_size = 4  # square 2x2

    nr_of_walls = random.randint(min_walls, max_walls)
    nr_of_coins = random.randint(min_coins, max_coins)

    # adding walls
    for i in range(nr_of_walls):
        wall_height = random.randint(min_wall_height, max_wall_height)
        wall_width = random.randint(min_wall_width, max_wall_width)
        plane = random.randint(0, 1)

        pos_x = random.randint(1, map_size - 2)
        pos_y = random.randint(1, map_size - 2)

        if plane == 0:
            tmp_x = pos_x
            pos_x = pos_y
            pos_y = tmp_x

        for x in range(pos_x, pos_x + wall_width, 1):
            for y in range(pos_y, pos_y + wall_height, 1):
                try:
                    game_map[x][y] = mapping["wall"]
                except:
                    pass

    # adding finish
    pos_x = 0
    pos_y = 0

    while not all([game_map[pos_x][pos_y] != mapping["wall"],
                   (pos_x + 1 < map_size - 1),
                   (pos_y + 1 < map_size - 1),
                   pos_x > 0,
                   pos_y > 0]):
        pos_x = random.randint(1, map_size - 2)
        pos_y = random.randint(1, map_size - 2)

    game_map[pos_x][pos_y] = mapping["finish"]
    # game_map[pos_x + 1][pos_y] = mapping["finish"]
    # game_map[pos_x][pos_y + 1] = mapping["finish"]
    # game_map[pos_x + 1][pos_y + 1] = mapping["finish"]

    # adding coins
    for i in range(nr_of_coins):
        pos_x = 0
        pos_y = 0

        while not (game_map[pos_x][pos_y] != mapping["wall"] and game_map[pos_x][pos_y] != mapping["coin"]
                   and game_map[pos_x][pos_y] != mapping["finish"]):
            pos_x = random.randint(1, map_size - 2)
            pos_y = random.randint(1, map_size - 2)

        game_map[pos_x][pos_y] = mapping["coin"]

    # adding player
    pos_x = 0
    pos_y = 0

    while not (game_map[pos_x][pos_y] != mapping["wall"] and
               game_map[pos_x][pos_y] != mapping["coin"] and
               game_map[pos_x][pos_y] != mapping["finish"]):

        pos_x = random.randint(1, map_size - 2)
        pos_y = random.randint(1, map_size - 2)

    game_map[pos_x][pos_y] = mapping["player"]

    # for line in game_map:
    #     print(line)

    return game_map


def generate_map_list(nr_of_maps, map_size):
    map_list = []
    for i in range(nr_of_maps):
        map_list.append(generate_maps(map_size))

    return map_list


if __name__ == "__main__":
    map_list = generate_map_list(nr_of_maps=3000, map_size=7)

    map_index = 0

    for created_map in map_list:
        with open('map{}.txt'.format(map_index), 'w') as f:
            for line in created_map:
                for item in line:
                    f.write("{} ".format(item))
                f.write("\n")
            map_index += 1
