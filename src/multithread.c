#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <pthread.h>

#define NUM_threads 4

void* alpha_control(void* arg) {
    FILE *fp = arg;

    if (fp == NULL) {
        perror("File");
        return (void*)EXIT_FAILURE;
    }
    
    printf("File aperto");
    pthread_exit(NULL);
}

int main() {
    FILE *fp = fopen("file.txt", "r");
    pthread_t thread[NUM_threads];

    pthread_create(&thread[0], fp, alpha_control, NULL);

    pthread_exit(NULL);
}