all: cliente.o caixa.o fila.o trabalho.o 
	gcc -g trabalho.o fila.o caixa.o cliente.o -o trabalho -Wall
	rm -f *.o
caixa.o:
	gcc -g -c caixa.c
trabalho.o:
	gcc -g -c trabalho.c
fila.o:
	gcc -g -c fila.c
cliente.o:
	gcc -g -c cliente.c
