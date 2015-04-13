#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>

namespace utility {
  std::string repeat(int, std::string);
  bool char_in_string(char, std::string);
  int rand_int(int, int);
  std::string num_to_str(int);
}

#endif // UTILITY_H_
