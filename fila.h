#ifndef _FILA_H
#define _FILA_H

typedef struct cliente {
	int cod, qtd, saldo;
} Cliente;

typedef struct fila {
	int front, end, tam, cap;
	Cliente* c;
} Fila;

void criafila(int tam);
int fila_vazia();
int fila_cheia();
void push_fila(Cliente c);
void pop_fila();
Cliente frente();

#endif

