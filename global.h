#ifndef FIRE_SIMULATION_CELLULAR_AUTOMATA_GLOBAL_H
#define FIRE_SIMULATION_CELLULAR_AUTOMATA_GLOBAL_H

#include <pthread.h>
#include "const.h"

extern long counter;
extern long thread_count;
extern Cell *current_map;
extern Cell *future_map;
extern pthread_mutex_t mutex_lock;
extern pthread_cond_t thread_treshold_cond;

extern unsigned int fire_start_prob_for_nb_burning1[];
extern unsigned int fire_start_prob_for_nb_burning2[];

#endif //FIRE_SIMULATION_CELLULAR_AUTOMATA_GLOBAL_H
