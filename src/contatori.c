#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <pthread.h>

#include "contatori.h"

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void* vocals_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        pthread_exit(NULL);
    }
    
    unsigned int local_counter = 0;
    char reader[256];

    while(fgets(reader, sizeof(reader), fp) != NULL) {
        for(int i = 0; reader[i] != '\0'; i++) {
            char ch = tolower(reader[i]);
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
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

void* consonants_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        pthread_exit(NULL);
    }
    
    unsigned int local_counter = 0;
    char reader[256];

    while(fgets(reader, sizeof(reader), fp) != NULL) {
        for(int i = 0; reader[i] != '\0'; i++) {
            char ch = tolower(reader[i]);
            if (isalpha(ch) && (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u')) {
                local_counter++;
            }
        }
    }

    pthread_mutex_lock(&mutex);
    c -> consonant_number = local_counter;
    pthread_mutex_unlock(&mutex);

    fclose(fp);
    pthread_exit(NULL);
}

void* punct_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        pthread_exit(NULL);
    }
    
    unsigned int local_counter = 0;
    char reader[256];

    while(fgets(reader, sizeof(reader), fp) != NULL) {
        for(int i = 0; reader[i] != '\0'; i++) {
            char ch = tolower(reader[i]);
            if (ispunct(ch)) {
                local_counter++;
            }
        }
    }

    pthread_mutex_lock(&mutex);
    c -> punct_number = local_counter;
    pthread_mutex_unlock(&mutex);

    fclose(fp);
    pthread_exit(NULL);
}

void* printable_counter(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_in, "r");

    if (fp == NULL) {
        perror("File");
        pthread_exit(NULL);
    }
    
    unsigned int local_counter = 0;
    unsigned int local_length_counter = 0;
    char reader[256];

    while(fgets(reader, sizeof(reader), fp) != NULL) {
        for(int i = 0; reader[i] != '\0'; i++) {
            local_length_counter++;
            char ch = tolower(reader[i]);
            if (isprint(ch)) {
                local_counter++;
            }
        }
    }

    pthread_mutex_lock(&mutex);
    c -> file_length = local_length_counter;
    c -> printable_number = local_counter;
    pthread_mutex_unlock(&mutex);

    fclose(fp);
    pthread_exit(NULL);
}