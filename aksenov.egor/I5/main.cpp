#include <iostream>
#include <readString.h>
#include "isFloat.h"
int main()
{
  size_t size = 0;
  size_t increaseCapacity = 50;
  char *cstr = nullptr;
  try
  {
    cstr = readString(std::cin, size, increaseCapacity);
  }
  catch (...)
  {
    std::cerr << "ERROR" << "\n";
    return 2;
  }
  std::cout << std::boolalpha << isFloat(cstr) << "\n";
  delete[] cstr;
  return 0;
}
