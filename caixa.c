#include "caixa.h"
#include "fila.h"
#include "relatorio.h"
#include <stdlib.h>

struct cliente {
	int cod, op, valor;
};

struct caixa {
	int topo, tam, cap;
	Cliente* c;
};

int caixa = 0, qtd;

Caixa* c;

void criacaixa(int qtd_clientes, int qtd_caixas){			//Função de iniciar fila
	int i, tam;
	if (qtd_clientes % qtd_caixas == 0) tam = qtd_clientes/qtd_caixas;
	else tam = qtd_clientes/qtd_caixas + 1;

	c = (Caixa*) malloc(qtd_caixas*sizeof(Caixa));
	if (c != NULL) {
		for (i=0; i<qtd_caixas; i++) {
			Caixa a = c[i];
			
				a.topo = -1;
				a.tam=0;
				a.cap=tam;
				a.c=(Cliente*) malloc(tam*sizeof(Cliente));
			
			c[i] = a;
		}
	}
	
	
	
	qtd = qtd_caixas;
	
}

int caixa_vazio(Caixa c){					//Função para checar se a fila está vazia
	return c.tam == 0;
}

int caixa_cheio(Caixa c){					//Função para checar se a fila está cheia
	return c.tam == c.cap;
}

Caixa push_caixa(Caixa caixa, Cliente c){				//Adiciona cliente na fila
	if (!caixa_cheio(caixa)){
		caixa.topo++;
		caixa.c[caixa.topo] = c;
		caixa.tam++;
	}
	return caixa;
}

Caixa pop_caixa(Caixa caixa){						//Retira cliente da fila
	if (!caixa_vazio(caixa)){	
		caixa.topo--;
		caixa.tam--;
	}
	return caixa;
}

Cliente topo(Caixa caixa){				//Retorna o primeiro da fila
	return caixa.c[caixa.topo];
}

void atende() {
	while (!fila_vazia()) {
		if (caixa == qtd) caixa = 0;
		c[caixa] = push_caixa(c[caixa++], frente());
		pop_fila();
	}
}

void armazena() {
	int i, j;
	for (i=0; i<qtd; i++) {
		Caixa a = c[i];
		for (j=a.tam; j>0; j--) {
			push_relatorio(a.c[a.topo]);
			a = pop_caixa(a);
		}
	}
}


