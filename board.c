#ifndef BOARD_DEFINITION
#define BOARD_DEFINITION

#include "board.h"

struct Board *make_board() {
  struct Board *board = (struct Board *)malloc(sizeof(struct Board));
  board->grid = (bool **)malloc(sizeof(bool *) * __GAME_DIMENSIONS__);
  for (unsigned int i = 0; i < __GAME_DIMENSIONS__; i++) {
    board->grid[i] = (bool *)malloc(__GAME_DIMENSIONS__ * sizeof(bool));
    for (unsigned int j = 0; j < __GAME_DIMENSIONS__; j++) {
      board->grid[i][j] = false;
    }
  }
  return board;
}

int free_board(struct Board *board) {
  for (unsigned int i = 0; i < __GAME_DIMENSIONS__; i++) {
    free(board->grid[i]);
  }
  free(board->grid);
  free(board);
  return 0;
}

int print_board(struct Board *board) {
  printf("  ");
  for (unsigned int row_header = 0; row_header < __GAME_DIMENSIONS__ - 1; row_header++) {
    printf("%d ", row_header);
  }
  printf("%d\n ", __GAME_DIMENSIONS__);
  for (unsigned int row_header_sep = 0; row_header_sep < __GAME_DIMENSIONS__;
       row_header_sep++) {
    printf("--");
  }
  printf("\n");
  for (unsigned int i = 0; i < __GAME_DIMENSIONS__; i++) {
    printf("%d|", i);
    for (unsigned int j = 0; j < __GAME_DIMENSIONS__; j++) {
      printf("%c ", (board->grid[i][j] ? 'Q' : '*'));
      // (day == SUNDAY) ? 12 : 9
    }
    printf("\n");
  }
  printf("\n");
  return 0;
}

bool is_possible(struct Board *board, unsigned int row, unsigned int col) {
  if ((row >= __GAME_DIMENSIONS__) || (col >= __GAME_DIMENSIONS__)) {
    // Invalid row/col index
    return false;
  } else if (board->grid[row][col]) {
    // Queen already placed here
    return false;
  }
  // check vertical and horizontal collisions
  for (unsigned int idx = 0; idx < __GAME_DIMENSIONS__; idx++) {
    if ((board->grid[row][idx]) || (board->grid[idx][col])) {
      return false;
    }
  }
  // check diagonal collisions
  for (unsigned int row_idx = 0; row_idx < __GAME_DIMENSIONS__; row_idx++) {
    for (unsigned int col_idx = 0; col_idx < __GAME_DIMENSIONS__; col_idx++) {
      if ((row_idx == row) && (col_idx == col)) {
        continue;
      } else if (board->grid[row_idx][col_idx]) {
        // m = (y2-y1) / (x2-x1)
        int m_div = (row_idx - row) / (col_idx - col);
        int m_rem = (row_idx - row) % (col_idx - col);

        if (((m_div == 1) || (m_div == -1)) && (!m_rem)) {
          return false;
        }
      }
    }
  }
  return true;
}

int place_queen(struct Board *board, unsigned int row, unsigned int col) {
  board->grid[row][col] = true;
  return 0;
}

#endif
