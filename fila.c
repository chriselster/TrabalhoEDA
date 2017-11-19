#include "fila.h"

int frente,fundo,n;
int *fila;

struct fila
{
	int frente,fundo,tam;
	struct cliente v[n];
};




fila* criafila(void){
	fila *x = (fila*) malloc(sizeof(struct fila));
	if (x!=NULL){
		x.frente=0;
		x.fundo=0;
		x.tam=0;
	}
	return x;
}

void push(flia *fila, cliente x){
	if (fila==NULL)return;
	if(!cheia(fila)){
		fila.v[fila.fundo] = x;
		fila.fundo++;
		if (fila.fundo == n)fila.fundo=0;
		fila.tam++;
	}
	return;
}


void pop(void){
	if (fila==NULL)return;
	if (!fila.vazia()){	
		fila.frente++;
		if (fila.frente==n)frente=0;
		fila.tam--;
	}
	return;
}
int vazia(flia *fila){
	return fila.frente==fila.fundo;
}
int cheia(flia *fila){
	return (u+1)%n==p;
}
