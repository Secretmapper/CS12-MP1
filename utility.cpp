#include "./utility.h"

#include <string>
#include <sstream>

namespace utility {
  std::string repeat(int n, std::string str) {
    std::ostringstream os;
    for (int i = 0; i < n; i++)
        os << str;
    return os.str();
  }
}
