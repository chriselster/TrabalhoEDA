#ifndef _FILA_H
#define _FILA_H

struct cliente
{
	int c,o,v;
};

typedef struct fila fila;

cliente* criafila(void);
void push(flia *fila, cliente x);
void pop(fila *fila);
void front();
int vazia(void);
int cheia(void);

#endif