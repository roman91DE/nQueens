#include "board.h"

int main(int argc, char **argv) {

  struct Board *board = make_board();
  print_board(board);
  free_board(board);

  return 0;
}