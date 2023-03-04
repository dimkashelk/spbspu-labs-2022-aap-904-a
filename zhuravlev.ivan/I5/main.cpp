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
    std::cerr << e.what();
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << "\n";
  return 0;
}

