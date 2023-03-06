#include <makeString.h>
#include <iostream>
#include "isRealNumber.h"

int main()
{
  size_t size = 0;
  size_t capacity = 10;
  try
  {
    char* cstring = makeCstring(capacity, size, std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  delete[] cstring;
  return 0;
}
