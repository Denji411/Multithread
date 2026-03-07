#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "contatori.h"
#include "report.h"

#define NUM_threads 4

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Numero di argomenti non valido.");
        return EXIT_FAILURE;
    }
    
    pthread_t thread;
    Conteggi *c = malloc(sizeof(Conteggi));
    c -> nome_file_in = "resources/file.txt";

    pthread_create(&thread, NULL, vocals_counter, c);
    pthread_create(&thread + 1, NULL, consonants_counter, c);
    pthread_create(&thread + 2, NULL, punct_counter, c);
    pthread_create(&thread + 3, NULL, printable_counter, c);

    pthread_join(thread, NULL);
    pthread_join(thread + 1, NULL);
    pthread_join(thread + 2, NULL);
    pthread_join(thread + 3, NULL);

    printf("Vocals: %ld\nConsonants: %ld\nPunct: %ld\nPrintable: %ld", c -> vocal_number, c -> consonant_number, c -> punct_number, c -> printable_number);

    pthread_create(&thread + 4, NULL, print_report, c);
    pthread_join(thread + 4, NULL);

    free(c);
    return EXIT_SUCCESS;
}