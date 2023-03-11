#ifndef BOARD_DECLARATION
#define DIM 9

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Board {
  bool **grid;
};

struct Board *make_board();
int free_board(struct Board *board);
int print_board(struct Board *board);

#endif