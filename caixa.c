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

int caixa = 0, qtd = 0; 												// Inicializa inteiro para caixa atual e quantidade de caixas

Caixa* c; 																// Declara ponteiro para os caixas

void criacaixa(int qtd_clientes, int qtd_caixas){						// Funcao de criar os caixas
	int i, tam;
	if (qtd_clientes % qtd_caixas == 0) tam = qtd_clientes/qtd_caixas;	// Verifica se a qtd de clientes eh divisivel pela qtd de caixas; se sim recebe o quociente
	else tam = qtd_clientes/qtd_caixas + 1; 							// Senao, recebe o quociente + 1 visto que aproxima para cima

	c = (Caixa*) malloc(qtd_caixas*sizeof(Caixa)); 						// Aloca o vetor de caixas
	if (c != NULL) { 													// Verifica se o ponteiro para o vetor nao eh nulo
		for (i=0; i<qtd_caixas; i++) { 									// Se sim, itera sobre a qtd de caixas para alocar cada pilha da caixa
			Caixa a = c[i];
			
			a.topo = -1; 												// O topo recebe -1 visto que o caixa esta vazio
			a.tam=0; 													// O tamanho recebe 0 
			a.cap=tam; 													// A capacidade recebe tam
			a.c=(Cliente*) malloc(tam*sizeof(Cliente)); 				// O ponteiro do tipo Cliente eh alocado como vetor de clientes
			
			c[i] = a; 													// Por fim, o conteudo do ponteiro para o caixa "i" recebe o caixa alocado "a"
		}
	}
	
	qtd = qtd_caixas; 
	
}

int caixa_vazio(Caixa c){												// Funcao para checar se o caixa esta vazio
	return c.tam == 0;
}

int caixa_cheio(Caixa c){												// Funcao para checar se o caixa esta cheio
	return c.tam == c.cap;
}

Caixa push_caixa(Caixa caixa, Cliente c){								// Funcao que insere um Cliente no caixa
	if (!caixa_cheio(caixa)) { 											// Verifica se o caixa nao esta cheio
		caixa.topo++; 													// Se sim, o topo eh incrementado para indicar a proxima posicao
		caixa.c[caixa.topo] = c; 										// No vetor de clientes na posicao "caixa.topo" recebe Cliente c
		caixa.tam++; 													// E o tamanho do caixa eh incrementado
	}

	return caixa; 														// Retorna o caixa modificado
}

Caixa pop_caixa(Caixa caixa){											// Funcao que retira um Cliente no caixa
	if (!caixa_vazio(caixa)) {											// Verifica se o caixa nao esta vazio	
		caixa.topo--; 													// Se sim, o topo eh decrementado
		caixa.tam--; 													// E o tamanho eh decrementado
	}
	
	return caixa; 														// Retorna o caixa modificado
}

Cliente topo(Caixa caixa){ 												// Funcao para retornar o topo do caixa
	return caixa.c[caixa.topo];
}

void atende() { 														// Funcao para atender os clientes presentes na fila
	while (!fila_vazia()) { 											// Enquanto a fila nao for vazia ele insere o cliente no caixa atual
		if (caixa == qtd) caixa = 0;
		c[caixa] = push_caixa(c[caixa++], frente()); 					// Insere no caixa atual
		pop_fila(); 													// Remove cliente da fila
	}
}

void armazena() { 														// Funcao para armazenar os clientes atendidos nos caixas na lista para a criacao do relatorio
	int i, j;
	for (i=0; i<qtd; i++) { 											// Iterando sobre os caixas
		Caixa a = c[i];
		for (j=a.tam; j>0; j--) { 
			push_relatorio(a.c[a.topo]);								// Adiciona o topo do caixa atual na lista
			a = pop_caixa(a); 											// Retira o elemento do topo
		}
	}
}


