#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include "report.h"
#include "contatori.h"

void* print_report(void* arg) {
    Conteggi *c = (Conteggi*)arg;
    // FIXME: cancella file .md nel caso ce ne fosse già presente uno
    FILE *fp = fopen(c -> nome_file_out, "w");

    if (fp == NULL) {
        perror("Errore di scrittura o creazione file");
        pthread_exit(NULL);
    }

    fprintf(fp, "# Rapporto analisi del File\n\n"
    "## Informazioni Generali\n\n"
    "- File analizzato: %s\n"
    "- Data esecuzione: %s\n\n"
    "## Risultati\n\n"
    "| Categoria    | Conteggio | Percentuale   |\n"
    "|--------------|-----------|---------------|\n"
    "| Vocali       | %d        | %f            |\n" // FIXME: percentuale che si ferma al centesimale
    "| Consonanti   | %d        | %f            |\n" // TODO: bordo destro sfora 
    "| Punteggiatura| %d        | %f            |\n"
    "| Stampabili   | %d        | %f            |\n"
    "|------------------------------------------|\n",
    c -> nome_file_in,
    asctime(c -> ptr),
    c -> vocal_number,
    ((double)c -> vocal_number / (double)c -> file_length) * 100,
    c -> consonant_number,
    ((double)c -> consonant_number / (double)c -> file_length) * 100,
    c -> punct_number,
    ((double)c -> punct_number / (double)c -> file_length) * 100,
    c -> printable_number,
    ((double)c -> printable_number / (double)c -> file_length) * 100);
    
    pthread_exit(NULL);
}