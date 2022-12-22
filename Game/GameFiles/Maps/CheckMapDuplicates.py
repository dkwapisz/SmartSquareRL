# Author:       Dawid Kwapisz (dkwapisz99@gmail.com, dkwapisz@student.agh.edu.pl)
# License:      GPLv3

from os import listdir

directory = "20x20Maps"
count_files = len(listdir(directory))
maps = set()

for i in range(0, count_files-1):
    with open("./{}/map{}.txt".format(directory, i)) as f:
        map_ = f.read()
        if map_ in maps:
            print("Found duplicate - map {}".format(i))
        else:
            maps.add(map_)

if len(maps) == count_files-1:
    print("Not found duplicates")

