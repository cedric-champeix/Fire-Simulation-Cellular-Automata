//
//  Cédric Champeix
//

#include <stdio.h>
#include "const.h"

void display_map_as_string(Cell *map) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%d ", map[j + i * MAP_SIZE].cell_type);
        }
        printf("\n");
    }
    printf("\n");
}
