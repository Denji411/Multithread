#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>                                                                                 

#include "contatori.h"
#include "report.h"

#define NUM_threads 5

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Numero di argomenti non valido.\n");
        return EXIT_FAILURE;
    } else if (argc > 2) {
        printf("Utilizzo %s\n", argv[1]);
    }
    
    pthread_t thread[NUM_threads];
    Conteggi *c = malloc(sizeof(Conteggi));
    c -> nome_file_in = "resources/file.txt";
    
    // analisi nome del file e prevenzione formato errato
    char *point = strchr(argv[1], '.');
    if (point != NULL) {    // sostituisco tutti i punti con \0
        *point = '\0';
    }

    int length = strlen(argv[1] + 3 + 1);   // dimensione argv[1] + .md + \0
    char *file_name = malloc(length * sizeof(char));

    if (file_name != NULL) {
        strcpy(file_name, argv[1]);
        strcat(file_name, ".md");
    }

    c -> nome_file_out = file_name;
    printf("%s\n", file_name);

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

    free(file_name);
    free(c);
    return EXIT_SUCCESS;
}