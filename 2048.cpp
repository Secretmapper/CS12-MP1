// preprocessor directives
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <functional>

#include "./2048.h"
#include "./utility.h"

#define CONTROL_STRING "WASDQ"

typedef struct Tile {
  /// x coordinate on board
  int x;
  /// y coordinate on board
  int y;
  /// actual value of tile
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

  if (this->filename != NULL) {
    this->loadGame();
  } else {
    memset(this->board, 0, sizeof this->board);
  }

  this->addTile();

  while (!this->hasReached2048() && this->hasMove()) {

    std::cout << std::endl;

    // clear screen
    if (system("cls")) system("clear");

    std::cout << "Score: " << this->score << std::endl;

    this->drawBoard();

    std::cout << "(W)Up (S)Down (A)Left (D)Right (Q)Quit: ";
    char input = this->getInput();

    if (input == 'Q') {
      // quit
      this->saveGame();
      break;
    } else {
      bool isMoved = this->move(input);
      if (isMoved) {
        this->addTile();
      }
    }
  }

  if (this->hasReached2048()) {
    if (system("cls")) system("clear");
    std::cout << "You won!" << std::endl;
  }
}

// private
Tile G2048::randomAvailableTile() {
  Tile tiles[4 * 4];
  int tiles_size = 0;

  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 4; x++) {
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
  tile.x = tile.y = tile.value = -1;

  if (tiles_size > 0) {
    this->hasAvailableTile = !(tiles_size == 1);
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
  } while (utility::char_in_string(input, CONTROL_STRING));

  return input;
}

bool G2048::move(char direction) {
  // last_index is the position which
  // can be merged to in the current run
  int last_index;
  bool isMoved = false;
  // should be refactored:
  switch (direction) {
    case 'W':
      for (int x = 0; x < 4; x++) {
        last_index = 0;
        int (&board)[4][4] = this->board;
        for (int y = 0; y <= 3; y++) {
          if (board[y][x] != 0 && last_index != y) {
            // if can merge or last_index is still empty
            if (board[y][x] == board[last_index][x] || board[last_index][x] == 0) {
              isMoved = true;
              bool merged = (board[y][x] == board[last_index][x]);
              board[last_index][x] = board[y][x] + board[last_index][x];
              board[y][x] = 0;
              // last index is now first tile after,
              // since it's now empty from the merge.
              if (merged) {
                this->score += board[last_index][x];
                last_index = last_index + 1;
              }
            } else {
              last_index = last_index + 1;
              board[last_index][x] = board[y][x];
              if (last_index != y) {
                isMoved = true;
                board[y][x] = 0;
              }
            }
          }
        }
      }

      break;
    case 'S':
      for (int x = 0; x < 4; x++) {
        last_index = 3;
        int (&board)[4][4] = this->board;
        for (int y = 2; y >= 0; y--) {
          if (board[y][x] != 0 && last_index != y) {
            // if can merge or last_index is still empty
            if (board[y][x] == board[last_index][x] || board[last_index][x] == 0) {
              isMoved = true;
              bool merged = (board[last_index][x] == board[y][x]);
              board[last_index][x] = board[y][x] + board[last_index][x];
              board[y][x] = 0;
              // last index is now first tile after,
              // since it's now empty from the merge.
              if (merged) {
                this->score += board[last_index][x];
                last_index = last_index - 1;
              }
            } else {
              last_index = last_index - 1;
              board[last_index][x] = board[y][x];
              if (last_index != y) {
                isMoved = true;
                board[y][x] = 0;
              }
            }
          }
        }
      }
      break;
    case 'A':
      for (int y = 0; y < 4; y++) {
        last_index = 0;
        int (&row)[4] = this->board[y];
        for (int x = 1; x <= 3; x++) {
          if (row[x] != 0 && last_index != x) {
            // if can merge or last_index is still empty
            if (row[x] == row[last_index] || row[last_index] == 0) {
              isMoved = true;
              bool merged = (row[x] == row[last_index]);
              row[last_index] = row[x] + row[last_index];
              row[x] = 0;
              // last index is now first tile after,
              // since it's now empty from the merge.
              if (merged) {
                this->score += row[last_index];
                last_index = last_index + 1;
              }
            } else {
              last_index = last_index + 1;
              row[last_index] = row[x];
              if (last_index != x) {
                isMoved = true;
                row[x] = 0;
              }
            }
          }
        }
      }
      break;
    case 'D':
      for (int y = 0; y < 4; y++) {
        last_index = 3;
        int (&row)[4] = this->board[y];
        for (int x = 2; x >= 0; x--) {
          if (row[x] != 0 && last_index != x) {
            // if can merge or last_index is still empty
            if (row[x] == row[last_index] || row[last_index] == 0) {
              isMoved = true;
              bool merged = (row[x] == row[last_index]);
              row[last_index] = row[x] + row[last_index];
              row[x] = 0;
              // last index is now first tile after,
              // since it's now empty from the merge.
              if (merged) {
                this->score += row[last_index];
                last_index = last_index - 1;
              }
            } else {
              last_index = last_index - 1;
              row[last_index] = row[x];
              if (last_index != x) {
                isMoved = true;
                row[x] = 0;
              }
            }
          }
        }
      }
      break;
  }

  return isMoved;
}

void G2048::drawBoard() {
  // add the first top lines
  std::cout << "+" << utility::repeat(4, " - - - - +") << std::endl;
  for (int y = 0; y < 4; y++) {
    // iteratively fill lower ends
    std::string str = utility::num_to_str(this->board[0][0]);

    std::cout << "|";
    for (int x = 0; x < 4; x++) {
      std::cout << std::setw(9) << this->board[y][x] << "|";
    }
    std::cout << std::endl;

    std::cout << "+" << utility::repeat(4, " - - - - +") << std::endl;
  }
  std::cout << std::endl;
}

bool G2048::hasReached2048() {
  for (int y = 0; y < 4; y++) {
    for (int x = 0; x < 4; x++) {
      if (this->board[y][x] == 2048) {
        return true;
      }
    }
  }
  return false;
}

bool G2048::hasMove() {
  if (this->hasAvailableTile) {
    return true;
  }

  int dirs[4][2] = {{0, -1},
                    {1 , 0},
                    {0 , 1},
                    {-1, 0}};
  // grid iteration
  for (int x = 0; x < 4; x++) {
    for (int y = 0; y < 4; y++) {
      // adjacency iteration
      for (int i = 0; i < 4; i++) {
        int _x = x + dirs[i][0];
        int _y = y + dirs[i][1];
        if ((_x == x && _y == y ) || _x < 0 || _x >= 4 || _y < 0 || _y >= 4)
          continue;
        if (this->board[y][x] == this->board[_y][_x])
          return true;
      }
    }
  }

  return false;
}

void G2048::loadGame() {
  std::fstream of(this->filename, std::ios::in);
  std::string line;

  for (int i = 0; i < 4; i++) {
    std::getline(of, line);
    std::stringstream  linestream(line);

    int value;
    for (int j = 0; j < 4; j++) {
      linestream >> value;
      this->board[i][j] = value;
    }
  }
  of.close();
}

void G2048::saveGame() {
  if (this->filename == NULL) {
    std::cout << "Type in a save file name: ";
    std::string filename = "";
    std::cin >> filename;
    this->filename = new char[filename.length() + 1];
    std::strcpy(this->filename, filename.c_str());
  }

  std::fstream of(this->filename, std::ios::out);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      of << this->board[i][j] << " ";
    }
    of << std::endl;
  }
  of.close();
}
