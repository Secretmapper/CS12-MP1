#ifndef UTILITY_H_
#define UTILITY_H_

#include <string>

namespace utility {
  /** Repeats string n times.
   * @param n How many times string is repeated.
   * @param str String to repeat.
   * @return String repeated n times.
   */
  std::string repeat(int n , std::string str);

  /** Checks if char is in string.
   * @param needle Character to find.
   * @param haystack String to find needle in.
   * @return Boolean wheter or not needle is in haystack.
   */
  bool char_in_string(char needle, std::string haystack);

  /** Random Integer within Range (inclusive)
   * @param a minimuim range.
   * @param b maximuim range (inclusive).
   * @throws InvalidArgumentException When b < a
   * @return Random number such that a <= n <= b.
   */
  int rand_int(int a, int b);

  /** Converts Integer to String
   */
  std::string num_to_str(int);
}

#endif // UTILITY_H_
