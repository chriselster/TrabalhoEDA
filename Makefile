all: fila
fila: fila.o trabalho.o 
	gcc -o trabalho fila.o trabalho.o
fila.o: fila.c
	gcc -o fila.o -c fila.c -W -Wall 
trabalho.o: trabalho.c fila.h
	gcc -o trabalho.o -c trabalho.c -W -Wall 
clean:
	rm -rf *.o
mrproper: clean
	rm -rf fila
