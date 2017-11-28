#include "cliente.h"
#include <stdlib.h>

Cliente cria_cliente(int cod, int op, int valor) {				//Retorna um novo cliente
	Cliente c = {cod, op, valor};
	return c;
}


