all: cliente.o pilha.o fila.o trabalho.o 
	gcc -g trabalho.o fila.o pilha.o cliente.o -o trabalho -Wall
	rm -f *.o
pilha.o:
	gcc -g -c pilha.c
trabalho.o:
	gcc -g -c trabalho.c
fila.o:
	gcc -g -c fila.c
cliente.o:
	gcc -g -c cliente.c
