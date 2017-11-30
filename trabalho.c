//MATA40 - Christian Elster e Igor de Almeida

#include "relatorio.h"
#include "fila.h"
#include "caixa.h"
#include <stdlib.h>
#include <stdio.h>

void read(){
	int m, n, i;					//m: número de caixas; n: número de clientes que passaram pelo banco; i: contador para loop
	scanf("%d %d", &m, &n);			//Lê valores de m e n
	
	criafila(n);					//cria-se uma nova fila com tamanho raiz de n
	criacaixa(n, m);				//criam-se caixas com tamanho n/m
	
	for (i = 1; i <= n; ++i) {		//loop para ler entradas dos clientes
			int cod, op, val;		//cod: código do cliente, op: operação feita (saque ou depósito);val: valor dessa operação
			scanf("%d %d %d", &cod, &op, &val);//lê-se os valores da entrada
		if (!fila_cheia()) {		//se a fila não estiver cheia
			push_fila(cod, op, val);//adiciona novo cliente ao fim da fila
			if (fila_cheia()) atende();//quando a fila enche os clientes nela são atendidos 
		} 
	}
	atende();			//se ao final do loop ainda houverem clientes na fila esses são atendidos	
	return;
}



int main() {
	read();				//funcao de leitura da entrada
	armazena();			//função para passar informações dos caixas para o relatório
	relatorio();		//função para imprimir o relatório
	return 0;
}
