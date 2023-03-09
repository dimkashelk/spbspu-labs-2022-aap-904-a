#include <iostream>
#include <cstring>
#include <stdexcept>
#include <myString.h>
#include "realNumber.h"

int main()
{
  size_t size = 0, capacity = 10;
  char* number = nullptr;
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
  std::cout << std::boolalpha << myRealNumber(number) << "\n";
  delete[] number;
  return 0;
}
