//
//  Cédric Champeix
//

#include <stdlib.h>
#include "const.h"
#include "global.h"

bool is_fire_spreading(Cell *map, int row, int col, unsigned int *random_seed) {
    int nb_burning = 0;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            int real_col = col + j;
            int real_row = row + i;

            real_col = real_col % MAP_SIZE >= 0 ? real_col : MAP_SIZE + real_col;
            real_row = real_row % MAP_SIZE >= 0 ? real_row : MAP_SIZE + real_row;

            int current_index = real_col + real_row * MAP_SIZE;

            if (map[current_index].cell_type == BURNING) {
                nb_burning++;
            }
        }
    }
    unsigned int burning_rand = ((unsigned int) rand_r(random_seed)) % 101;
    if (burning_rand < fire_start_prob_for_nb_burning2[nb_burning]) {
        return true;
    }
    return false;
}


