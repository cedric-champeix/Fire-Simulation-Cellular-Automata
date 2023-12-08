//
//  Cédric Champeix
//

#include <pthread.h>
#include <stdio.h>

#include "const.h"
#include "global.h"
#include "my_functions.h"

void *calc_fire_evolution_parallel(void *rank) {
    long my_rank = (long) rank;

    int size = MAP_SIZE / thread_count;
    int start_index = (int) my_rank * size;
    int end_index = ((int) my_rank + 1) * size;

    unsigned int thread_seed = (unsigned int) time(NULL);

    for (int i = 0; i < NB_IT; i++) {

        long current_index = start_index * MAP_SIZE;

        for (int row = start_index; row < end_index; row++) {
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
                        if (is_fire_spreading(current_map, row, col, &thread_seed)) {
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

        pthread_mutex_lock(&mutex_lock);

        counter++;
        if (counter == thread_count) {
            swap_maps(&current_map, &future_map);
            write_day(i+1, current_map);
            counter = 0;
            pthread_cond_broadcast(&thread_treshold_cond);
        } else {
            pthread_cond_wait(&thread_treshold_cond, &mutex_lock);
        }

        pthread_mutex_unlock(&mutex_lock);


    }

    return NULL;
}
