#ifndef _FILA_H
#define _FILA_H
#include <stdlib.h>

// Declara structs

typedef struct fila Fila;
typedef struct cliente Cliente;

// Declara funcoes

void criafila(int tam);
int fila_vazia();
int fila_cheia();
void push_fila(int cod, int op, int valor);
void pop_fila();
Cliente frente();

#endif

