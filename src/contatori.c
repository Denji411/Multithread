#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>

#include "contatori.h"

void* vocals_counter(void* arg) {
    char* nome_file = (char*)arg;
    FILE *fp = fopen(nome_file, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto\n");
    pthread_exit(NULL);
}

void* consonants_counter(void* arg) {
    char* nome_file = (char*)arg;
    FILE *fp = fopen(nome_file, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto\n");
    pthread_exit(NULL);
}

void* punct_counter(void* arg) {
    char* nome_file = (char*)arg;
    FILE *fp = fopen(nome_file, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto\n");
    pthread_exit(NULL);
}

void* printable_counter(void* arg) {
    char* nome_file = (char*)arg;
    FILE *fp = fopen(nome_file, "r");

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto\n");
    pthread_exit(NULL);
}