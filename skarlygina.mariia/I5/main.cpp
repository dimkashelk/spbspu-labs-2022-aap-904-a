#include <iostream>
#include <iomanip>
#include <cstring_capacity.h>
#include "is_float_digit.h"

int main()
{
  char* digit_string = makeNewCapacityCString(std::cin);
  std::cout << std::boolalpha << isFloatDigit(digit_string) << '\n';
  delete[] digit_string;
  return 0;
}
