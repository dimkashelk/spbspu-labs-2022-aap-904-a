#include <iostream>
#include <string>
#include <cstrfnc.h>
#include "isreal.h"

int main()
{
  int rc = 0;
  std::pair< char*, size_t > strPair = std::make_pair(nullptr, 0);
  try
  {
    std::cout << "Enter real number: ";
    strPair = getCString(std::cin);
    std::cout << std::boolalpha << isReal(strPair.first) << "\n";
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    rc = 1;
  }
  if (strPair.first)
  {
    delete[] strPair.first;
  }
  return rc;
}
