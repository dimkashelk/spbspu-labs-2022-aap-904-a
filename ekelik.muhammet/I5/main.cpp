#include <iostream>
#include <cstring>
#include <stdexcept>
#include <myString.h>
#include "realNumber.h"

int main()
{
  char* number = nullptr;
  size_t size = 0, capacity = 300;
  try
  {
    number = makeMyString(size, capacity, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what() << "\n";
    delete[] number;
    return 1;
  }
  std::cout << std::boolalpha << isRealNumber(number) << "\n";
  delete[] number;
  return 0;
}
