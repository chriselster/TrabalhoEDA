#include "cliente.h"
#include "fila.h"
#include <stdlib.h>

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
	return f->front == -1 || f->front>f->end;
}

int fila_cheia(){					//Função para checar se a fila está cheia
	return f->end==f->cap-1;
}

void push_fila(int cod, int qtd, int saldo, Cliente (*criar) (int, int, int)){				//Adiciona cliente na fila
	if (f==NULL) return;
	if (fila_vazia()) f->front++;
	if (!fila_cheia()){
		Cliente c = (*criar)(cod, qtd, saldo);
		f->end++;
		if (f->end == f->cap) f->end=0;
		f->c[f->end] = c;
		f->tam++;
	}
}

void pop_fila(){						//Retira cliente da fila
	if (f==NULL)return;
	if (!fila_vazia()){	
		f->front++;
		if (f->front==f->cap) f->front=0;
		f->tam--;
	}
}

Cliente frente(){				//Retorna o primeiro da fila
	return f->c[f->front];

}


