#ifndef _FILA_H
#define _FILA_H
#include "cliente.h"

typedef struct fila Fila;

void criafila(int tam);
int fila_vazia();
int fila_cheia();
void push_fila(int cod, int qtd, int saldo, Cliente (*criar) (int, int, int));
void pop_fila();
Cliente frente();

#endif

