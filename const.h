#ifndef FIRE_SIMULATION_CELLULAR_AUTOMATA_CONST_H
#define FIRE_SIMULATION_CELLULAR_AUTOMATA_CONST_H

#include <stdbool.h>

#define MAP_SIZE 128
#define NB_IT 50
#define FUEL_DURATION 3
#define FIRE_START_THRESHOLD 2
#define FIRE_START_PROB 1000

typedef enum {
    NOT_FUEL, FUEL, BURNT, BURNING
} CellType;

typedef struct {
    CellType cell_type;
    char fuel_days;
} Cell;

#endif