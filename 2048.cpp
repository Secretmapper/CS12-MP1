// preprocessor directives
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>

#include "./2048.h"
#include "./utility.h"

#define CONTROL_STRING "WASDQ"

typedef struct Tile {
  /// x coordinate on board
  int x;
  /// x coordinate on board
  int y;
  /// x coordinate on board
  int value;
} tile;

// implement the functions declared for the G2048 class here
G2048::G2048(char* filename) {
  this->filename = filename;
  this->score = 0;
  this->hasAvailableTile = true;
}

void G2048::startGame() {
  srand(time(0));

  memset(this->board, 0, sizeof this->board);

  while (!this->hasReached2048() && this->hasAvailableTile) {
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
Tile G2048::randomAvailableTile() {
  Tile tiles[4 * 4];
  int tiles_size = 0;

  for (int y = 0; y < 4; y++) {
    for(int x = 0; x < 4; x++) {
      if (this->board[y][x] == 0) {
        Tile tile;
        tile.x = x;
        tile.y = y;
        tile.value = this->board[y][x];
        tiles[tiles_size] = tile;
        tiles_size++;
      }
    }
  }
  Tile tile;
  if(tiles_size == 0) {
    this->hasAvailableTile = false;
    tile.x = tile.y = tile.value = -1;
  } else {
    tile = tiles[utility::rand_int(0, tiles_size - 1)];
  }
  return tile;
}

void G2048::addTile() {
  int value = (utility::rand_int(0, 1) == 0) ? 2 : 4;
  Tile tile = randomAvailableTile();
  if (tile.x != -1)
    this->board[tile.y][tile.x] = value;
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
    std::string str = utility::num_to_str(this->board[0][0]);

    std::cout << "|";
    for(int x = 0; x < 4; x++) {
      std::cout << std::setw(9) << this->board[y][x] << "|";
    }
    std::cout << std::endl;

    std::cout << "+" << utility::repeat(4, " - - - - +") << std::endl;
  }
  std::cout << std::endl;
}

bool G2048::hasReached2048() {
  return false;
}
