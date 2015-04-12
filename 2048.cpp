// preprocessor directives
#include <fstream>
#include <iostream>
#include <string>

#include "./2048.h"
#include "./utility.h"

// implement the functions declared for the G2048 class here
G2048::G2048(char* filename) {
  this->filename = filename;
}

void G2048::startGame() {
  memset(this->board, 0, sizeof this->board);

  this->score = 0;
  this->drawBoard();
}

// private
void G2048::addTile() {
}

char G2048::getInput() {
  return 'a';
}

bool G2048::move(char direction) {
  if (direction) {}
  return true;
}

void G2048::drawBoard() {
  // add the first top lines
  std::cout << "+" << utility::repeat(4, " - - - - +") << std::endl;
  for (int y = 0; y < 4; y++) {
    // iteratively fill lower ends
    std::cout << "|" << utility::repeat(4, "         |") << std::endl;
    std::cout << "+" << utility::repeat(4, " - - - - +") << std::endl;
  }
}

bool G2048::hasReached2048() {
  return false;
}
