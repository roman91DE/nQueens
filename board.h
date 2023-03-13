#ifndef BOARD_DECLARATION
#define BOARD_DECLARATION

#define __GAME_DIMENSIONS__ 8

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Board {
  bool **grid;
};

struct Board *make_board();
int free_board(struct Board *board);
int print_board(struct Board *board);
bool is_possible(struct Board *board, unsigned int row, unsigned int col);
int place_queen(struct Board *board, unsigned int row, unsigned int col);

#endif