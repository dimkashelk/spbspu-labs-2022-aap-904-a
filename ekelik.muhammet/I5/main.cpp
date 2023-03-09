#include <iostream>
#include <cstring>
#include <stdexcept>
#include <myString.h>
#include "realNumber.h"

int main()
{
  char* number = nullptr;
  size_t size = 0, capacity = 10;
  try
  {
    number = makeMyString(size, capacity, std::cin);
    bool mEkel1k = myRealNumber(number);
    std::cout << std::boolalpha << mEkel1k << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    delete[] number;
    return 1;
  }
  delete[] number;
  return 0;
}
