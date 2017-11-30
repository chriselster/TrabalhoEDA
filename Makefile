# Ao final da execução será criado um arquivo executável chamado "trabalho"

all: caixa.o fila.o relatorio.o trabalho.o 
	gcc -g trabalho.o relatorio.o fila.o caixa.o -o trabalho -Wall
	rm -f *.o
relatorio.o:
	gcc -g -c relatorio.c
caixa.o:
	gcc -g -c caixa.c
trabalho.o:
	gcc -g -c trabalho.c
fila.o:
	gcc -g -c fila.c
clean:
	rm trabalho