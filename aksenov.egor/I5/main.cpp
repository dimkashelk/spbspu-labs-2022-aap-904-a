#include <iostream>
#include <readString.h>
#include "isFloat.h"
int main()
{
  size_t size = 0;
  size_t increaseCapacity = 20;
  char *cstr = new char[size];
  try
  {
    cstr = readString(std::cin, size, increaseCapacity);
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstr) << "\n";
  delete[] cstr;
}
