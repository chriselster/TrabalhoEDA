#ifndef _CLIENTE_H
#define _CLIENTE_H

typedef struct cliente {
	int cod, qtd, saldo;
} Cliente;

Cliente cria_cliente(int cod, int qtd, int saldo);

#endif

