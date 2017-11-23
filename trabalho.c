#include <stdlib.h>
#include <stdio.h>
/*#include "caixa.h"*/
#include "fila.h"




/*void atende(fila,caixa);
void relatorio();
void imprime();*/

void read(void){
	int m,n,raiz=1;
	scanf("%d %d", &m, &n);
	while((raiz*raiz)<n)raiz++;
	/*for (int i = 0; i < n; ++i)
	{
		cliente prox;
		scanf("%d %d %d", prox.c, prox.o, prox.v);
		fila.push(prox);
	}*/
}

int main()
{
	read();
	fila *fila=criafila();
	cliente a,b;
	a.c = 1; a.o=0; a.v=0;
	b.c = 2; b.o=0; b.v=0;
	push(fila,a);
	push(fila,b);
	for (int i = 0; i < 2; ++i)
	{
		printf("%d\n", front(fila).c);
		pop(fila);
	}

	return 0;
}
