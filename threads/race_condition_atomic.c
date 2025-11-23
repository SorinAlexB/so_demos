#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>
#include <time.h>

#define NUM_ITERATIONS 10000000

atomic_int global_var = 0;

void increment_thread(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        atomic_fetch_add(&global_var, 1);
    }
}

void decrement_thread(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        atomic_fetch_sub(&global_var, 1);
    }
}

int main() {

    pthread_t t1, t2;
    
    pthread_create(&t1, NULL, increment_thread, NULL);
    pthread_create(&t2, NULL, decrement_thread, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    int result = atomic_load(&global_var);
    printf("Valoarea lui global_var: %d\n",global_var);
    
    return 0;
}