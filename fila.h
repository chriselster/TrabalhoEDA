#ifndef _FILA_H
#define _FILA_H

int raiz;

typedef struct cliente
{
	int c,q,s;
}cliente;

typedef struct fila fila;

fila* criafila(void);
void push(fila *fila, cliente x);
void pop(fila *fila);
cliente front(fila *fila);
int vazia(fila *fila);
int cheia(fila *fila);

#endif
