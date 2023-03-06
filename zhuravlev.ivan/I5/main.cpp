#include <makeString.h>
#include <iostream>
#include "isRealNumber.h"

int main()
{
  size_t size = 0;
  size_t capacity = 10;
  char* cstring = makeCstring(capacity, size, std::cin);
  if (cstring[0] == '\n')
  {
    std::cerr << "Empty string";
    delete[] cstring;
    return 2;
  }
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  delete[] cstring;
  return 0;
}
