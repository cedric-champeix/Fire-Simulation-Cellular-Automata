#
# Cédric Champeix
#

import os
import numpy as np

PATH = "./maps_files"
NB_MAP = 0

class Map:
    def __init__(self):
        maps_list = os.listdir(PATH)
        self.maps = {}

        for file in maps_list:
            nb = file.split('-')[0]
            self.maps[nb] = file

        global NB_MAP
        NB_MAP = len(self.maps)
        self.map_size = 0


        self._init_board()

    def _init_board(self):
        with open(os.path.join(PATH, self.maps["0"]), "r") as map_data:
            line = map_data.readline()
            elems = [*line]
            elems.pop(-1)

            self.map_size = len(elems)
            self.mat = np.full((self.map_size, self.map_size), 0, int)

    def update(self, index: int):
        with open(os.path.join(PATH, self.maps[str(index)]), "r") as map_data:
            for i in range(self.map_size):
                line = map_data.readline()
                elems = [*line]
                elems.pop(-1)
                for j in range(self.map_size):
                    self.mat[i][j] = int(elems[j])

        return self.mat
