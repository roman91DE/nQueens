#include "board.h"

int main(int argc, char **argv) {

  struct Board *board = make_board();
  unsigned int row_buf;
  unsigned int col_buf;
  unsigned int queens_placed = 0;

  printf("Let's play a Game of n-Queens!\n");
  while (queens_placed < __GAME_DIMENSIONS__ - 1) {
    printf("Your current Board:\n");
    print_board(board);
    printf("Enter the row and column indices to place your Queen:\n");

    if (scanf("%d %d", &row_buf, &col_buf) != 2) {
      printf("Invalid Input. Please try again!\n");
      continue;
    }

    if (!is_possible(board, row_buf, col_buf)) {
      printf("Illegal Position. Please try again!\n");
      continue;
    }
    place_queen(board, row_buf, col_buf);
    queens_placed++;
  }

  free_board(board);
  return 0;
}