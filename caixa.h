#ifndef _CAIXA_H
#define _CAIXA_H
#include <stdio.h>

typedef struct caixa Caixa;
typedef struct cliente Cliente;

void criacaixa(int qtd_clientes, int qtd_caixas);
int caixa_vazio(Caixa c);
int caixa_cheio(Caixa c);
Caixa push_caixa(Caixa caixa, Cliente c);
Caixa pop_caixa(Caixa caixa);
Cliente topo(Caixa caixa);
void atende();
void armazena();

#endif


