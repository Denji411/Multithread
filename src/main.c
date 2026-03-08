#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "contatori.h"
#include "report.h"

#define NUM_threads 5

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Numero di argomenti non valido.\n");
        return EXIT_FAILURE;
    }
    
    pthread_t thread[NUM_threads];
    Conteggi *c = malloc(sizeof(Conteggi));
    c -> nome_file_in = "resources/file.txt";

    pthread_create(&thread[0], NULL, vocals_counter, c);
    pthread_create(&thread[1], NULL, consonants_counter, c);
    pthread_create(&thread[2], NULL, punct_counter, c);
    pthread_create(&thread[3], NULL, printable_counter, c);

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    pthread_join(thread[2], NULL);
    pthread_join(thread[3], NULL);

    printf("File Length: %d\nVocals: %d\nConsonants: %d\nPunct: %d\nPrintable: %d\n", c -> file_length, c -> vocal_number, c -> consonant_number, c -> punct_number, c -> printable_number);

    pthread_create(&thread[4], NULL, print_report, c);
    pthread_join(thread[4], NULL);

    free(c);
    return EXIT_SUCCESS;
}