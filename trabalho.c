#include <stdlib.h>
#include <stdio.h>
/*#include "caixa.h"*/
#include "fila.h"
int raiz=1;



/*void atende(fila,caixa);
void relatorio();
void imprime();*/

void read(fila *fila){
	int m,n;
	scanf("%d %d", &m, &n);
	while((raiz*raiz)<n)raiz++;
	printf("%d %d\n",raiz,n );
	for (int i = 0; i < n; ++i)
	{
		cliente x;
		x.q=0;
		x.s=0;
		int o,v;
		scanf("%d %d %d",&x.c,&o,&v);
		push(fila,x);
	}
	return;
}

int main()
{
	fila *fila=criafila();
	read(fila);
	for (int i = 0; i < raiz; ++i)
	{

		printf("%d\n", front(fila).q);
		pop(fila);
	}

	return 0;
}
