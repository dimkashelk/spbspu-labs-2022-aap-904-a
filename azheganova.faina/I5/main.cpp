#include <iostream>
#include <cstddef>
#include <inputstring.h>
#include "rowvalidation.h"


int main()
{
  char *cstring = inputString(std::cin);
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete [] cstring;
}
