#ifndef _CLIENTE_H
#define _CLIENTE_H

typedef struct cliente {
	int cod, op, valor;
} Cliente;

Cliente cria_cliente(int cod, int op, int valor);

#endif

