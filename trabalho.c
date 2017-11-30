#include "relatorio.h"
#include "fila.h"
#include "caixa.h"
#include <stdlib.h>
#include <stdio.h>

void read(){
	int m, n, i;
	scanf("%d %d", &m, &n);			//Le valores de m e n
	
	criafila(n);
	criacaixa(n, m);
	
	for (i = 1; i <= n; ++i) {
		if (!fila_cheia()) {
			int cod, op, val;
			scanf("%d %d %d", &cod, &op, &val);
			push_fila(cod, op, val);
			if (fila_cheia()) atende();
		} 
	}
		
	return;
}



int main() {
	read();				//Funcao de leitura da entrada
	armazena();
	relatorio();
	return 0;
}
