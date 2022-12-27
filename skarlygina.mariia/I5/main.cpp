#include <iostream>
#include <iomanip>
#include <exception>
#include <cstring_capacity.h>
#include "is_float_digit.h"

int main()
{
  char* digit_string = nullptr;
  try
  {
    digit_string = makeNewCapacityCString(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }
  std::cout << std::boolalpha << isFloatDigit(digit_string) << '\n';
  delete[] digit_string;
  return 0;
}
