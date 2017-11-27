#include "cliente.h"
#include <stdlib.h>

Cliente cria_cliente(int cod, int qtd, int saldo) {				//Retorna um novo cliente
	Cliente c = {cod, qtd, saldo};
	return c;
}


