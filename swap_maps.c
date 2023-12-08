//
//  Cédric Champeix
//

#include "const.h"

void swap_maps(Cell **_current_map, Cell **_future_map) {
    Cell *temp = (*_current_map);
    (*_current_map) = (*_future_map);
    (*_future_map) = temp;
}
