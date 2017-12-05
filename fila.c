#include "fila.h"
#include <stdlib.h>

struct cliente {
	int cod, op, valor;
};

struct fila {
	int front, end, tam, cap;
	Cliente* c;
};

Fila* f; 												// Declara ponteiro para fila

void criafila(int tam){									// Funcao para criar a fila
	int i, raiz;
	for (i=1; i*i<=tam; i++) raiz = i; 					// Loop para descobrir floor(raiz de tam)
	f = (Fila*) malloc(sizeof(Fila)); 					// Aloca a fila
	if (f!=NULL){ 										// Se nao for nula, realizamos os ajustes para criacao
		f->front=-1; 									// O front da fila recebe -1 pois ela esta vazia inicialmente
		f->end=-1; 										// Igualmente o end da fila recebe -1
		f->tam=0; 										// Tam recebe 0
		f->cap=raiz; 									// Cap recebe raiz que é o tamanho da fila
		f->c=(Cliente*) malloc(raiz*sizeof(Cliente)); 	// O ponteiro c é alocado como vetor de Clientes
	}
}

int fila_vazia(){										// Funcao para verificar se a fila esta vazia
	return f->tam == 0;
}

int fila_cheia(){										// Funcao para verificar se a fila esta cheia
	return f->tam==f->cap;
}

void push_fila(int cod, int op, int valor){				// Funcao para inserir um cliente na fila
	if (f==NULL) return; 								// Se a fila nao foi alocada corretamente e for nula, retornamos
	if (f->front == -1) f->front++; 					// Se o front for -1, incrementamos o front
	if (!fila_cheia()) { 								// Se a fila nao estiver cheia, significa que podemos inserir um cliente nela
		f->end++; 										// Para isso, incrementamos o end
		if (f->front == f->cap) f->front=0; 			// Se o front for igual ao tamanho total da fila, front recebe 0 visto que ela eh circular
		if (f->end == f->cap) f->end=0; 				// Se o end for igual ao tamanho total da fila, end recebe 0 visto que ela eh circular
		Cliente a = {cod, op, valor}; 					// Criamos a movimentacao do cliente "a"
		f->c[f->end] = a; 								// Inserimos ele no final da fila
		f->tam++; 										// E incrementamos o tamanho atual da fila
	}
}

void pop_fila(){										// Funcao para remover um cliente da fila
	if (f==NULL)return; 								// Se a fila nao foi alocada corretamente e for nula, retornamos
	if (!fila_vazia()) { 								// Se a fila nao estiver vazia, significa que podemos remover um cliente dela
		if (f->front == f->cap) f->front=0;				// Se o front for igual ao tamanho total da fila, front recebe 0 visto que ela eh circular
		f->front++; 									// Incrementamos o front
		f->tam--; 										// E decrementamos o tamanho atual da fila
	}
}

Cliente frente(){										// Funcao para retornar o primeiro cliente da fila
	return f->c[f->front];
}


