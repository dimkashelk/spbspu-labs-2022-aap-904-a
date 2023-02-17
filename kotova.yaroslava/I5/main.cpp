#include <iostream>
#include <cstddef>
#include <FormingCstring.h>
#include "digit.hpp"

int main()
{
  char* cstring = nullptr;
  try
  {
    cstring = formingCstring(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isFloat(cstring) << '\n';
  delete[] cstring;
}
