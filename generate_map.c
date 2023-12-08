//
//  Cédric Champeix
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "const.h"

void generate_map(Cell *map) {
    srand(1);
    int index = 0;
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++, index++) {
            unsigned char cell_type = (unsigned char) rand() % 100;
            if (cell_type > 20) {
                unsigned int burning_rand = (unsigned int) rand() % FIRE_START_PROB;

                if (burning_rand < FIRE_START_THRESHOLD) {
                    map[index].cell_type = BURNING;
                    map[index].fuel_days = FUEL_DURATION;
                } else {
                    map[index].cell_type = FUEL;
                    map[index].fuel_days = FUEL_DURATION - 1;
                }
            } else {

                map[index].cell_type = NOT_FUEL;
                map[index].fuel_days = 0;
            }
        }
    }
}
