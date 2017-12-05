#include "relatorio.h"
#include <stdlib.h>
#include <stdio.h>

struct cliente {
	int cod, op, valor; 
};

struct node {							 
	int cod, qtd;			 
	long long saldo;				 
	Node *prox, *ant; 
};

int L = 0;		   //contador do número de clientes adicionados ao relatório
Node *atual, *ini; //nó atual aponta para a última modificação e ini sempre para o começo da lista

void push_relatorio(Cliente a)
{ //Adiciona nó no relatório a partir das informações do cliente "a"

	if (a.op)
	{ //se op=1(saque) o valor se torna negativo, senão permanece o mesmo
		a.valor = -(a.valor);
	}

	if (atual == NULL)
	{											   //se o relatório estiver vazio adiciona novo nó
		L++;									   //incrementa contador
		Node *novo = (Node *)malloc(sizeof(Node)); //aloca espaço para o novo nó
		novo->cod = a.cod;						   //novo nó recebe código do cliente a
		novo->qtd = 1;							   //quantidade de operações do novo nó recebe 1 (primeira ocorrência desse cliente)
		novo->saldo = a.valor;					   //saldo recebe valor da operação (motivo análogo ao anterior)
		novo->prox = novo->ant = NULL;			   //ponteiros do novo cliente apontam para NULL, pois está sozinho na lista
		atual = novo;							   //atual recebe local da última inserção
		ini = novo;								   //ini aponta para o início do relatório
		return;
	}

	if (atual->cod == a.cod)
	{							 //se o cliente a ser adicionado é aquele apontado por atual
		atual->qtd++;			 //incrementa a quantidade de operações desse cliente
		atual->saldo += a.valor; //saldo é incrementado o valor da nova operação desse cliente (seja o valor positivo ou negativo)
		return;
	}

	if (atual->cod > a.cod)
	{ //se o código do cliente a ser inserido for inferior ao qual o relatório aponta
		for (; atual->ant != NULL && a.cod < atual->ant->cod; atual = atual->ant); //busca entre os valores inferiores

		/*O loop para se encontrar a extremidade da lista ou se o valor do 
			cliente anterior for menor ou igual ao do cliente a ser adicionado, de qualquer forma
			o novo cliente será adicionado na posição anterior àquela do ponteiro atual*/

		Node *aux = atual->ant; //ponteiro auxilhar aponta para o nó anterior àquele apontado por atual
		if (aux)
		{ //se aux != NULL
			if (aux->cod == a.cod)
			{						   //se o código do anterior for igual ao do novo cliente
				aux->qtd++;			   //incrementa a quatidade de operações
				aux->saldo += a.valor; //atualiza saldo
				atual = aux;		   //atual aponta para a última modificação
				return;				   //(nesse caso o contador não aumenta pois o cliente já existia)
			}
			Node *novo = (Node *)malloc(sizeof(Node)); //aloca espaço para o novo nó
			L++;									   //contador aumenta (pois houve criação de um novo nó)
			novo->cod = a.cod;						   //novo nó recebe código do cliente
			novo->qtd = 1;							   //quantidade de operações do novo nó recebe 1 (primeira ocorrência desse cliente)
			novo->saldo = a.valor;					   //saldo recebe valor da operação (motivo análogo ao anterior)
			aux->prox = novo;						   //nó anterior aponta para o novo nó
			novo->ant = aux;						   //novo nó aponta atrás para o anterior
			novo->prox = atual;						   //e à frente para o atual
			atual->ant = novo;						   //nó seguinte aponta para o novo nó
			atual = novo;							   //atual aponta para a última modificação
			return;
		}
		else
		{											   //se aux == NULL (chegou à extremidade inferior da lista encadeada)
			Node *novo = (Node *)malloc(sizeof(Node)); //mesmo processo
			L++;
			novo->cod = a.cod;
			novo->qtd = 1;
			novo->saldo = a.valor;
			novo->prox = atual; //exeto que não há nó anterior para apontar para o novo nó
			novo->ant = NULL;   //análogamente novo nó aponta para NULL
			atual->ant = novo;
			atual = novo;
			ini = novo; //pois novo nó está no início da lista
			return;
		}
	}
	else
	{

		for (; atual->prox != NULL && a.cod > atual->prox->cod; atual = atual->prox); //busca entre os valores superiores

		/*O loop para se encontrar a extremidade da lista ou se o valor do próximo
			cliente for maior ou igual ao do cliente a ser adicionado, de qualquer forma
			o novo cliente será adicionado na posição seguinte àquela do ponteiro atual*/

		Node *aux = atual->prox; //ponteiro auxilhar aponta para o nó seguinte àquele apontado por atual
		if (aux)
		{ //se aux != NULL
			if (aux->cod == a.cod)
			{						   //se o código do próximo nó for igual ao do novo cliente
				aux->qtd++;			   //incremente quatidade de operações
				aux->saldo += a.valor; //atualiza saldo
				atual = aux;		   //atual aponta para a última modificação
				return;
			}
			Node *novo = (Node *)malloc(sizeof(Node)); //processo análogo ao já apresentado
			L++;
			novo->cod = a.cod;
			novo->qtd = 1;
			novo->saldo = a.valor;
			aux->ant = novo;
			novo->prox = aux;  //novo nó aponta à frente para o seguinte
			novo->ant = atual; //e atrás para o atual
			atual->prox = novo;
			atual = novo; //atual aponta para a última modificação
			return;
		}
		else
		{		 //se aux == NULL (chegou à extremidade superior da lista encadeada)
			L++; //similar a quando chega na extremidade oposta, porém início não se altera
			Node *novo = (Node *)malloc(sizeof(Node));
			novo->cod = a.cod;
			novo->qtd = 1;
			novo->saldo = a.valor;
			atual->prox = novo;
			novo->ant = atual;
			novo->prox = NULL;
			atual = novo;
			return;
		}
	}
}

void relatorio()
{					   //função para imprimir o relatório
	printf("%d\n", L); //imprime quantidade total de clientes que passaram pelo banco
	Node *aux = ini;   //ponteiro auxiliar aponta para o primeiro elemento da lista
	while (aux != NULL)
	{														   //enquanto o auxiliar não apontar para NULL
		printf("%d %d %lld\n", aux->cod, aux->qtd, aux->saldo); //imprime informações do nó apontado e quebra de linha
		aux = aux->prox;									   //nó auxiliar passa a apontar para o nó seguinte
	}
}
