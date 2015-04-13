#include "./utility.h"

#include <string>
#include <sstream>
#include <stdexcept>
#include <sstream>

namespace utility {
  std::string repeat(int n, std::string str) {
    std::ostringstream os;
    for (int i = 0; i < n; i++)
        os << str;
    return os.str();
  }

  bool char_in_string(char needle, std::string haystack) {
    return haystack.find_first_of(needle) == std::string::npos;
  }

  int rand_int(int min, int max) { 
    if(max < min) {
      throw std::invalid_argument( "Empty range for rand_int (max arg is more than min arg)" );
    }
    return rand() % ((max + 1) - min) + min;
  }
  
  std::string num_to_str (int t) {
    std::ostringstream stream;
    stream << t;
    return stream.str();
  }
}
