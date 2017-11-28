#include "cliente.h"
#include "relatorio.h"
#include <stdlib.h>



struct node
{
	int cod,qtd,saldo;
	Node* prox, ant;
};


Node* atual,ini;

void push_relatorio(Cliente a){	//Adiciona nó no relatório
	 //criar novo

	//consulta(cod); Vê se cod já existe

	novo->cod = cod;
	novo->qtd = 1;
	novo->saldo += valor;
	if (atual==NULL){ 
		novo->prox = novo->ant = NULL;
		atual=novo;
		ini = novo;
		
		return;
	}

	if(atual->cod > cod){
		for(; atual->ant != NULL && cod > atual->ant->cod; atual=atual->ant);
			Node aux=atual->ant;

		if(aux){
			aux->prox=novo;
			novo->ant=aux;
			atual->ant=novo;
			novo->prox=atual;
			atual=novo;
			return;
		}else{
			atual->ant=novo;
			novo->prox=atual;
			atual=novo;
			ini=novo;
			return;
		}
	}else{

		for(; atual->prox != NULL && cod < atual->prox->cod; atual=atual->prox);
				Node aux=atual->prox;

			if(prox){
				aux->ant=novo;
				novo->prox=aux;
				atual->prox=novo;
				novo->ant=atual;
				atual=novo;
				return;
			}else{
				atual->prox=novo;
				novo->ant=atual;
				atual=novo;
				return;
			}
		}


	//criar função pra descobrir onde adicionar
	if (atual)
	{
		if (novo->cod>atual->cod){
			while(novo->cod>atual->prox->cod){
				atual=atual->prox;
			}
			if (novo->cod==atual->prox->cod)
			{
				atual->prox->cod//faz operações lá
			}else{
				Node* aux=atual->prox;
				atual->prox= novo;
				novo->prox=aux;
				aux->ant= novo;
				novo->ant=atual;
			}
		}
	}else


	//atual aponta para anterior

	
}