CC = gcc
CFLAGS = -g -Wall
OBJS = main.o board.o

all: prog

prog: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o prog

main.o: main.c board.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

clean:
	rm -f *.o prog
