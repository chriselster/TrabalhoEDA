#include <stdlib.h>
#include <stdio.h>
#include "caixa.h"
#include "fila.h"


void atende(fila,caixa);
void relatorio();
void imprime();

void read(void){
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; ++i)
	{
		cliente prox;
		scanf("%d %d %d", prox.c, prox.o, prox.v);
		fila.push(prox);
	}
}

int main()
{
	fila* fila;
	fila=criafila();
	a.push()
	return 0;
}