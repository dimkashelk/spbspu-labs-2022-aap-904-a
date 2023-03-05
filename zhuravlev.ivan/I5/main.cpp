#include <makeString.h>
#include <iostream>
#include "functions.h"

int main()
{
  char* cstring = nullptr;
  try
  {
    cstring = makeCstring(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  delete[] cstring;
  return 0;
}
