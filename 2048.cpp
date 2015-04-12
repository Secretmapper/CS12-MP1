// preprocessor directives
#include <fstream>
#include <iostream>
#include <string>

#include "./2048.h"
#include "./utility.h"

#define CONTROL_STRING "WASDQ"

// implement the functions declared for the G2048 class here
G2048::G2048(char* filename) {
  this->filename = filename;
  this->score = 0;
}

void G2048::startGame() {
  memset(this->board, 0, sizeof this->board);


  while (!this->hasReached2048()) {
    //clear screen
    if (system("cls")) system("clear");

    this->drawBoard();

    std::cout << "(W)Up (S)Down (A)Left (D)Right (Q)Quit: ";
    char input = this->getInput();

    if(input == 'Q') {
      //quit
    } else {
      this->move(input);
    }

    this->addTile();
  }
}

// private
void G2048::addTile() {
}

char G2048::getInput() {
  char input;
  do {
    std::cin >> input;
    // while not inputting any char in WASDQ
  } while(utility::char_in_string(input, CONTROL_STRING));
  
  return input;
}

bool G2048::move(char direction) {
  switch(direction) {
      case 'W':
        break;
      case 'A':
        break;
      case 'S':
        break;
      case 'D':
        break;
    }
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
  std::cout << std::endl;
}

bool G2048::hasReached2048() {
  return false;
}
