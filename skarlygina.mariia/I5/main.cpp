#include <iostream>
#include <iomanip>
#include <cstring_capacity.h>
#include "is_float_digit.h"

int main()
{
  char* string = makeNewCapacityCString(std::cin);
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete[] cstring;
  return 0;
}
