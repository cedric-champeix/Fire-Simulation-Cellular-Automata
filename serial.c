//
//  Cédric Champeix
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "my_functions.h"

unsigned int fire_start_prob_for_nb_burning1[] = {0, 50, 60, 70, 80, 90, 100, 100, 100};
unsigned int fire_start_prob_for_nb_burning2[] = {0, 30, 40, 50, 60, 70, 80, 90, 100};

int main(int argc, char **argv) {

    Cell *current_map = malloc(sizeof(Cell) * MAP_SIZE * MAP_SIZE);
    Cell *future_map = malloc(sizeof(Cell) * MAP_SIZE * MAP_SIZE);
    assert(current_map != NULL && future_map != NULL &&
           "Memory allocation failed.");

    generate_map(current_map);

    init_write();
    write_day(0, current_map);

    unsigned int random_seed = 1;

    clock_t begin = clock();
    for (int i = 0; i < NB_IT; i++) {

        long current_index = 0;
        for (int row = 0; row < MAP_SIZE; row++) {
            for (int col = 0; col < MAP_SIZE; col++) {

                Cell current_cell = current_map[current_index];

                switch (current_cell.cell_type) {
                    case BURNING:
                        if (current_cell.fuel_days == 0) {
                            current_cell.cell_type = BURNT;
                        } else {
                            current_cell.fuel_days--;
                        }
                        break;
                    case FUEL:
                        if (is_fire_spreading(current_map, row, col, &random_seed)) {
                            current_cell.cell_type = BURNING;
                            current_cell.fuel_days--;
                        }
                        break;
                    default:
                        break;
                }

                future_map[current_index] = current_cell;
                current_index++;
            }
        }

        swap_maps(&current_map, &future_map);
        write_day(i+1, current_map);
    }

    clock_t end = clock();
    printf("Time: %lf\n", ((double) (end - begin) / CLOCKS_PER_SEC));

    free(current_map);
    free(future_map);
}
