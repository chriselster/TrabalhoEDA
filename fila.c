#include "fila.h"
#include <stdlib.h>

Fila* f;

void criafila(int tam){
	int i, raiz;
	for (i=1; i*i<=tam; i++) raiz = i;
	f = (Fila*) malloc(sizeof(Fila));
	if (f!=NULL){
		f->front=0;
		f->end=-1;
		f->tam=-1;
		f->cap=raiz;
		f->c=(Cliente*) malloc(raiz*sizeof(Cliente));
	}
}

int vazia(){
	return f->front==f->end;
}

int cheia(){
	return f->end==f->cap-1;
}

void push(Cliente c){
	if (f==NULL) return;
	if (vazia()) f->front++;
	if (!cheia()){
		f->end++;
		if (f->end == f->cap) f->end=0;
		f->c[f->end] = c;
		f->tam++;
	}
}

void imprime() {
	int i, cont=f->front;
}
/*

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

*/
