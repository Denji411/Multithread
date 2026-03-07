#ifndef CONTATORI_H
#define CONTATORI_H

typedef struct 
{
    FILE *fp;

    long vocal_number;
    long consonant_number;
    long punct_number;
    long printable_number;
} Conteggi;

void* vocals_counter(void* arg);
void* consonants_counter(void* arg);
void* punct_counter(void* arg);
void* printable_counter(void* arg);

#endif