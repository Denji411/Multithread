#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "contatori.h"
#include "report.h"

#define NUM_threads 4

int main() {
    pthread_t thread;
    char* nome_file = "resources/file.txt";

    pthread_create(&thread, NULL, vocals_counter, nome_file);
    pthread_create(&thread + 1, NULL, consonants_counter, nome_file);
    pthread_create(&thread + 2, NULL, punct_counter, nome_file);
    pthread_create(&thread + 3, NULL, printable_counter, nome_file);

    pthread_join(thread, NULL);
    pthread_join(thread + 1, NULL);
    pthread_join(thread + 2, NULL);
    pthread_join(thread + 3, NULL);

    pthread_create(&thread + 4, NULL, print_report, nome_file);

    return EXIT_SUCCESS;
}