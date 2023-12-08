#ifndef FIRE_SIMULATION_CELLULAR_AUTOMATA_MY_FUNCTIONS_H
#define FIRE_SIMULATION_CELLULAR_AUTOMATA_MY_FUNCTIONS_H

#include "const.h"

void generate_map(Cell *map);

void *calc_fire_evolution_parallel(void *data);

void swap_maps(Cell **_current_map, Cell **_future_map);

bool is_fire_spreading(Cell *map, int row, int col, unsigned int *random_seed);

void display_map_as_string(Cell *map);

void init_write();

void write_day(int day, Cell *map);

#endif //FIRE_SIMULATION_CELLULAR_AUTOMATA_MY_FUNCTIONS_H
