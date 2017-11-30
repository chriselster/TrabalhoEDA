#include "relatorio.h"
#include <stdlib.h>
#include <stdio.h>

struct cliente {
	int cod, op, valor;
};

struct node {
	int cod,qtd,saldo;
	struct node *prox, *ant;
};

int L = 0;

Node *atual,*ini;

void push_relatorio(Cliente a){	//Adiciona nó no relatório
	if (a.cod > L) L = a.cod;
	
	if (a.op){				//se op=1(saque) o valor se torna negativo
		a.valor=-(a.valor);
	}

	if (atual==NULL){ 		//se o relatório estiver vazio adiciona novo nó
		Node* novo=(Node*)malloc(sizeof(Node));
		novo->cod=a.cod;
		novo->qtd=1;
		novo->saldo=a.valor;
		novo->prox = novo->ant = NULL;
		atual = novo;
		ini = novo;	
		return;
	}

	if (atual->cod == a.cod){
		atual->qtd++;
		atual->saldo += a.valor;
		return;
	}
	
	if(atual->cod > a.cod){		//se o código do cliente à ser inserido for inferior ao qual o relatório aponta
		for(; atual->ant != NULL && a.cod < atual->ant->cod; atual=atual->ant);	//busca entre os valores inferiores
			Node *aux= atual->ant;
			if(aux){
				if (aux->cod==a.cod){	//se o código do anterior for igual ao do novo cliente
					aux->qtd++;			//incremente quatidade de operações
					aux->saldo += a.valor;	//atualiza saldo
					atual=aux;			//relatório aponta para onde ocorreu a alteração
					return;
				}
				Node* novo=(Node*)malloc(sizeof(Node));
				novo->cod=a.cod;
				novo->qtd=1;
				novo->saldo=a.valor;
				aux->prox=novo;
				novo->ant=aux;
				atual->ant=novo;
				novo->prox=atual;
				atual=novo;
				return;
			}else{
				Node* novo=(Node*)malloc(sizeof(Node));
				novo->cod=a.cod;
				novo->qtd=1;
				novo->saldo=a.valor;	
				atual->ant=novo;
				novo->prox=atual;
				novo->ant=NULL;
				atual=novo;
				ini=novo;
				return;
			}
		
	}else{

		for(; atual->prox != NULL && a.cod > atual->prox->cod; atual=atual->prox);	//busca entre os valores superiores
			Node *aux=atual->prox;
			if(aux){
				if (aux->cod==a.cod){
					aux->qtd++;
					aux->saldo += a.valor;
					atual=aux;
					return;			
				}
				Node* novo=(Node*)malloc(sizeof(Node));
				novo->cod=a.cod;
				novo->qtd=1;
				novo->saldo=a.valor;
				aux->ant=novo;
				novo->prox=aux;
				atual->prox=novo;
				novo->ant=atual;
				atual=novo;
				return;
			}else{
				Node* novo=(Node*)malloc(sizeof(Node));
				novo->cod=a.cod;
				novo->qtd=1;
				novo->saldo=a.valor;
				atual->prox=novo;
				novo->ant=atual;
				novo->prox=NULL;
				atual=novo;
				return;
			}
		}
}

void relatorio() {
	printf("%d\n", L);
	Node* aux = ini;
	while (aux != NULL) {
		printf("%d %d %d\n", aux->cod, aux->qtd, aux->saldo);
		aux = aux->prox;
	}
	printf("\n");
}

