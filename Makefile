all: cliente.o caixa.o fila.o relatorio.o trabalho.o 
	gcc -g trabalho.o relatorio.o fila.o caixa.o cliente.o -o trabalho -Wall
	rm -f *.o
relatorio.o:
	gcc -g -c relatorio.c
caixa.o:
	gcc -g -c caixa.c
trabalho.o:
	gcc -g -c trabalho.c
fila.o:
	gcc -g -c fila.c
cliente.o:
	gcc -g -c cliente.c
clean:
	rm trabalho