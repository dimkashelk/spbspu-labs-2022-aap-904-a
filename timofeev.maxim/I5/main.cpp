#include <iostream>
#include <cstddef>
#include "isExpression.h"
#include <inputStr.h>

int main()
{
  char *str = nullptr;
  size_t size = 0;
  try
  {
    str = inputStr(std::cin, size);
  }
  catch (...)
  {
    std::cerr << "Error" << "\n";
    return 2;
  }
  std::cout << std::boolalpha << isExpression(str) << "\n";
  return 0;
}
