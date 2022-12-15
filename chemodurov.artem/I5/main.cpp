#include <iostream>
#include <extendCString.h>
#include <getCString.h>
#include "isRealNumber.h"

int main()
{
  char * c_string = chemodurov::getCString(std::cin);
  std::cout << std::boolalpha << chemodurov::isRealNumber(c_string) << "\n";
  delete [] c_string;
  return 0;
}
