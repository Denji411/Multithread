#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "report.h"
#include "contatori.h"

void* print_report(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    FILE *fp = fopen(c -> nome_file_out, "r");

    fprintf(fp, "# Rapporto analisi del File\n\n");
    fprintf(fp, "## Informazioni Generali\n\n");
    fprintf(fp, "- File analizzato: %s\n", c -> nome_file_in);
    fprintf(fp, "- Data esecuzione: "); //continua...

    pthread_exit(NULL);
}