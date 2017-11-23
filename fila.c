#include "fila.h"
#include <stdlib.h>


struct fila
{
	int frente,fundo,tam;
	cliente* v;
};


fila* criafila(void){
	cliente* a= (cliente*) malloc(raiz*sizeof(cliente));
	fila* x= (fila*) malloc(sizeof(fila));
	if (x!=NULL){
		x->frente=0;
		x->fundo=0;
		x->tam=0;
		x->v=a;
	}
	return x;
}

void push(fila *fila, cliente x){
	if (fila==NULL)return;
	if(!cheia(fila)){
		fila->v[fila->fundo] = x;
		fila->fundo++;
		if (fila->fundo == raiz)fila->fundo=0;
		fila->tam++;
	}
	return;
}


void pop(fila *fila){
	if (fila==NULL)return;
	if (!vazia(fila)){	
		fila->frente++;
		if (fila->frente==raiz)fila->frente=0;
		fila->tam--;
	}
	return;
}

cliente front(fila *fila){
	return fila->v[fila->frente];

}

int vazia(fila *fila){
	return fila->frente==fila->fundo;
}

int cheia(fila *fila){
	int a=(fila->fundo+1), b=fila->frente;
	if (a==raiz){
		a=0;
	}
	return a==b;
}
