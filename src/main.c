#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_threads 4

int main() {
    pthread_t thread[NUM_threads];
    char* nome_file = "resources/file.txt";

    pthread_create(&thread[0], NULL, vocals_counter, nome_file);

    pthread_exit(NULL);
}