#ifndef BOARD_DEFINITION

#include "board.h"

struct Board *make_board() {
  struct Board *board = (struct Board *)malloc(sizeof(struct Board));
  board->grid = (bool **)malloc(sizeof(bool *) * DIM);
  for (unsigned int i = 0; i < DIM; i++) {
    board->grid[i] = (bool *)malloc(DIM * sizeof(bool));
    for (unsigned int j = 0; j < DIM; j++) {
      board->grid[i][j] = false;
    }
  }
  return board;
}

int free_board(struct Board *board) {
  for (unsigned int i = 0; i < DIM; i++) {
    free(board->grid[i]);
  }
  free(board->grid);
  free(board);
  return 0;
}

int print_board(struct Board *board) {
  for (unsigned int i = 0; i < DIM; i++) {
    for (unsigned int j = 0; j < DIM; j++) {
      printf("%d ", board->grid[i][j]);
    }
    printf("\n");
  }
  return 0;
}

#endif
