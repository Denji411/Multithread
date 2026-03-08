#ifndef CONTATORI_H
#define CONTATORI_H

typedef struct
{
    char *nome_file_in;
    char *nome_file_out;

    unsigned int file_length;
    unsigned int vocal_number;
    unsigned int consonant_number;
    unsigned int punct_number;
    unsigned int printable_number;
} Conteggi;

void* vocals_counter(void* arg);
void* consonants_counter(void* arg);
void* punct_counter(void* arg);
void* printable_counter(void* arg);

#endif