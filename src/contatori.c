#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>

#include "contatori.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* vocals_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto\n");
    fclose(fp);
    pthread_exit(NULL);
}

void* consonants_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    unsigned int local_counter;
    char reader[256];

    while(fgets(reader, sizeof(reader), fp) != NULL) {
        for(int i = 0; reader[i] != "\0"; i++) {
            char ch = tolower(reader[i]);
            if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u") {
                local_counter++;
            }
        }
    }

    pthread_mutex_lock(&mutex);
    c -> vocal_number = local_counter;
    pthread_mutex_unlock(&mutex);

    fclose(fp);
    pthread_exit(NULL);
}

void* punct_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto\n");
    fclose(fp);
    pthread_exit(NULL);
}

void* printable_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto\n");
    fclose(fp);
    pthread_exit(NULL);
}