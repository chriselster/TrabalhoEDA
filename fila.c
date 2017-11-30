#include "fila.h"
#include <stdlib.h>
#include <stdio.h>

struct cliente {
	int cod, op, valor;
};

struct fila {
	int front, end, tam, cap;
	Cliente* c;
};

Fila* f;

void criafila(int tam){			//Função de iniciar fila
	int i, raiz;
	for (i=1; i*i<=tam; i++) raiz = i;
	f = (Fila*) malloc(sizeof(Fila));
	if (f!=NULL){
		f->front=-1;
		f->end=-1;
		f->tam=0;
		f->cap=raiz;
		f->c=(Cliente*) malloc(raiz*sizeof(Cliente));
	}
}

int fila_vazia(){					//Função para checar se a fila está vazia
	return f->tam == 0;
}

int fila_cheia(){					//Função para checar se a fila está cheia
	return f->tam==f->cap;
}

void push_fila(int cod, int op, int valor){				//Adiciona cliente na fila
	if (f==NULL) return;
	if (f->front == -1) f->front++;
	if (!fila_cheia()){
		f->end++;
		if (f->front == f->cap) f->front=0;
		if (f->end == f->cap) f->end=0;
		Cliente a = {cod, op, valor};
		f->c[f->end] = a;
		f->tam++;
	}
}

void pop_fila(){						//Retira cliente da fila
	if (f==NULL)return;
	if (!fila_vazia()){
		if (f->front==f->cap) f->front=0;	
		f->front++;
		f->tam--;
	}
}

Cliente frente(){				//Retorna o primeiro da fila
	return f->c[f->front];
}


