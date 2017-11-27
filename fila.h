#ifndef _FILA_H
#define _FILA_H

typedef struct cliente {
	int cod, op, val;
} Cliente;

typedef struct fila {
	int front, end, tam, cap;
	Cliente* c;
} Fila;

void criafila(int tam);
int vazia();
int cheia();

void push(Cliente c);
void imprime();
/*void pop(fila *fila);
cliente front(fila *fila);

*/
#endif

