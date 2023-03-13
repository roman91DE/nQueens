CC = gcc
CFLAGS = -g -Wall # -Ofast
OBJS = main.o board.o

all: nQueens

nQueens: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o nQueens

main.o: main.c board.h
	$(CC) $(CFLAGS) -c main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c board.c

clean:
	rm -f *.o nQueens

