#include "cliente.h"
#include "relatorio.h"
#include "fila.h"
#include <stdlib.h>
#include <stdio.h>



/*void read(){
	int m,n;
	scanf("%d %d", &m, &n);			//Lê valores de m e n

	for (int i = 0; i < n; ++i)
	{
		cliente x;
		x.qtd=0;
		x.saldo=0;
		int o,v;
		scanf("%d %d %d",&x.c,&o,&v);
		push(x);
		if (filaCheia())
		{
			atende();
		}
	}
	return;
}
*/


int main() {
	//read();				//Função de leitura da entrada
	//relatorio();
	//imprime();
	Cliente a={1,0,30};
	Cliente b={2, 1, 20};
	Cliente c={2,0,10};
	Cliente d={2,0,10};
	Cliente e={3,0,10};
	Cliente f={2,0,10};

	push_relatorio(f);
	push_relatorio(a);
	push_relatorio(b);
	push_relatorio(e);
	push_relatorio(d);
	push_relatorio(c);

	while(ini){
		int a,b,c;
		a=ini->cod;
		b=ini->qtd;
		c=ini->saldo;
		printf("Cliente:%d Qtd:%d Saldo:%d\n", a,b,c);
		ini=ini->prox;
	}
	return 0;
}
