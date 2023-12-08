//
//  Cédric Champeix
//

#include <assert.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "my_functions.h"

long counter = 0;
long thread_count;
Cell *current_map;
Cell *future_map;
pthread_mutex_t mutex_lock;
pthread_cond_t thread_treshold_cond;

unsigned int fire_start_prob_for_nb_burning1[] = {0, 50, 60, 70, 80, 90, 100, 100, 100};
unsigned int fire_start_prob_for_nb_burning2[] = {0, 30, 40, 50, 60, 70, 80, 90, 100};

int main(int argc, char **argv) {
    // Init threads
    pthread_t *thread_handler;

    thread_count = strtol(argv[1], NULL, 10);
    thread_handler = malloc(thread_count * sizeof(pthread_t));

    // Init mutex
    assert(pthread_mutex_init(&mutex_lock, NULL) == 0 && "Mutex initialisation failed.");

    // Init map
    current_map = malloc(sizeof(Cell) * MAP_SIZE * MAP_SIZE);
    future_map = malloc(sizeof(Cell) * MAP_SIZE * MAP_SIZE);
    assert(current_map != NULL && future_map != NULL && "Memory allocation failed.");

    generate_map(current_map);

    init_write();
    write_day(0, current_map);

    clock_t begin = clock();
    // Creates threads
    for (long thread_nb = 0; thread_nb < thread_count; thread_nb++) {
        pthread_create(&thread_handler[thread_nb], NULL, calc_fire_evolution_parallel, (void *) thread_nb);
    }

    // Join threads
    for (int i = 0; i < thread_count; i++) {
        pthread_join(thread_handler[i], NULL);
    }

    clock_t end = clock();
    printf("Time: %lf\n", ((double) (end - begin) / CLOCKS_PER_SEC));

    free(thread_handler);
    free(current_map);
    free(future_map);
    pthread_mutex_destroy(&mutex_lock);
}
