#include <iostream>
#include <cstddef>
#include "rowvalidation.h"
#include "inputstring.h"

int main()
{
  char *cstring = nullptr;
  cstring = inputString(std::cin);
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete[] cstring;
}
