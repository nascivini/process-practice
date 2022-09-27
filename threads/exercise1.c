#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_THREADS 10
int global_counter = 0;
void *func1(void *arg);

int main() {
    pthread_t my_threads[MAX_THREADS];
    void *ret;

    for(int i = 0; i < MAX_THREADS; i++){
        int status = pthread_create(&my_threads[i], NULL, func1, (void *) &i);
    }

    for(int i = 0; i < MAX_THREADS; i++) {
        pthread_join(my_threads[i], &ret);
    }
    printf("Program exited with counter on %d\n", global_counter);
    pthread_exit(NULL);
}

void *func1(void *arg) {
    pthread_t id = pthread_self();
    printf("Nova thread criada. TID = %lu\n ", id);
    for(int i = 0; i < 100; i++){
        global_counter++;
    }
    pthread_exit(NULL);
}
