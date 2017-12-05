//MATA40 - Christian Elster e Igor de Almeida

#include "relatorio.h"
#include "fila.h"
#include "caixa.h"
#include <stdlib.h>
#include <stdio.h>

void read() {
	int m, n, i;								// Declara os inteiros m e n da entrada, tal que "m" eh o numero de caixas e "n" eh o numero de clientes 
	scanf("%d %d", &m, &n); 					// Le valores de m e n

	criafila(n);	 							// Cria-se uma nova fila com tamanho raiz de n
	criacaixa(n, m); 							// Criam-se os caixas com tamanho ceil(n/m)

	for (i = 1; i <= n; i++) { 					// Para cada cliente realizamos uma movimentacao
		int cod, op, val; 						// Declara os inteiros cod, op e val; cod=codigo do cliente | op=operacao do cliente | val=valor para operacao
		scanf("%d %d %d", &cod, &op, &val); 	// Le os valores de cod, op e val
		
		if (!fila_cheia()) { 					// Se a fila nao estiver cheia, adicionamos um cliente na fila
			push_fila(cod, op, val); 			// Adiciona cliente na fila
			if (fila_cheia()) atende();			// Se a fila estiver cheia apos a adicao, os clientes presentes nela seguem para atendimento nos m caixas ate a fila ficar vazia
		}
	}
	
	atende(); 									// Se ainda houverem clientes a serem atendidos, enviamos eles para os m caixas
	return;
}

int main() {
	read();		 								// Funcao para ler as entradas e alocar os clientes nos caixas disponiveis
	armazena();  								// Funcao para armazenar os dados das movimentacoes numa lista linear ordenada para confeccao do relatorio
	relatorio(); 								// Funcao para imprimir o relatorio final
	return 0;
}
