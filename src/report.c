#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "report.h"

void* print_report(void* arg) {
    pthread_exit(NULL);
}