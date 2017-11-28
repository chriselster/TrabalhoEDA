#ifndef _RELATORIO_H
#define _RELATORIO_H
#include "cliente.h"

typedef struct node Node;

typedef struct relatorio Relatorio;

void criarelatorio(void);
void push_relatorio(int cod, int qtd, int saldo, int pos, Node (*criar) (int, int, int));

#endif