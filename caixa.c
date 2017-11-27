#include "cliente.h"
#include "caixa.h"
#include <stdlib.h>

struct caixa {
	int topo, tam, cap;
	Cliente* c;
};

Caixa* c;

void criacaixa(int qtd_clientes, int qtd_caixas){			//Função de iniciar fila
	int tam;
	if (qtd_clientes % qtd_caixas == 0) tam = qtd_clientes/qtd_caixas;
	else tam = qtd_clientes/qtd_caixas + 1;

	c = (Caixa*) malloc(qtd_caixas*sizeof(Caixa));

	if (c!=NULL){
		c->topo = -1;
		c->tam=0;
		c->cap=tam;
		c->c=(Cliente*) malloc(tam*sizeof(Cliente));
	}
}
/*
int caixa_vazia(){					//Função para checar se a fila está vazia
	return p->topo == -1;
}

int fila_cheia(){					//Função para checar se a fila está cheia
	return f->end==f->cap-1;
}

void push_fila(Cliente c){				//Adiciona cliente na fila
	if (f==NULL) return;
	if (fila_vazia()) f->front++;
	if (!fila_cheia()){
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


*/