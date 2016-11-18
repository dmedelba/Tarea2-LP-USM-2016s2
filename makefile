CC=gcc
DEBUG=-g
CFLAGS=-Wall

default: e

e: main.o lista.o CartaCurso.o Sansano.o
	$(CC) $^ -o $@

%.o: %.c
	$(CC) -c $^ $(CFLAGS)

clean:
	rm *.o e
