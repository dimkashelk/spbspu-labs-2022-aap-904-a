#include <iostream>
#include <myString.h>
#include "real_number.h"

int main()
{
  char* number = nullptr;
  size_t size = 0, capacity = 10;
  try
  {
    number = makeMyString(size, capacity, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << RealNumber(number) << "\n";
  delete[] number;
  return 0;
}
