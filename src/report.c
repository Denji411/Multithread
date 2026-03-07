#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "report.h"
#include "contatori.h"

void* print_report(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    
    
    pthread_exit(NULL);
}