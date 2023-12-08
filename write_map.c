//
//  Cédric Champeix
//

#include <stdio.h>
#include "const.h"

void write_day(int day, Cell* map) {
    char filename[50];
    sprintf(filename, "maps_files/%d-map", day);

    FILE *fptr = fopen(filename, "w");

    for (int y = 0; y < MAP_SIZE; ++y) {
        for (int x = 0; x < MAP_SIZE; ++x) {
            int current_index = x + y * MAP_SIZE;
            fprintf(fptr, "%d", map[current_index].cell_type);
        }
        fprintf(fptr, "\n");
    }

    fclose(fptr);
}