#ifndef _RELATORIO_H
#define _RELATORIO_H
#include "cliente.h"


typedef struct node
{
	int cod,qtd,saldo;
	struct node *prox, *ant;
} Node;

Node *atual,*ini;

void push_relatorio(Cliente a);

#endif