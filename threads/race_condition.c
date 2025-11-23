#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

#define NUM_ITERATIONS 10000000

int global_var = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void increment_thread(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        //pthread_mutex_lock(&mutex); 
        global_var++;
        //pthread_mutex_unlock(&mutex); 
    }
}

void decrement_thread(void *arg) {
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        //pthread_mutex_lock(&mutex); 
        global_var--;
        //pthread_mutex_unlock(&mutex); 
    }
}

int main() {

    pthread_t t1, t2;
    
    // Cream thread-urile
    pthread_create(&t1, NULL, increment_thread, NULL);
    pthread_create(&t2, NULL, decrement_thread, NULL);
    
    // Asteptam finalizarea
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    printf("Valoarea lui global_var: %d\n", global_var);
    
    return 0;
}
