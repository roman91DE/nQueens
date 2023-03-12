#include "board.h"

int main(int argc, char **argv) {

  struct Board *board = make_board();

  print_board(board);
  place_queen(board, 4, 4);
  printf("Is possible: %d\n", is_possible(board, 5, 3));
  place_queen(board, 5, 3);
  print_board(board);

  free_board(board);
  return 0;
}