#include <iostream>
#include <cstddef>
#include <cStrFromInput.h>
#include "isExpression.h"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  char* cStr = nullptr;
  try
  {
    cStr = new char[capacity];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  try
  {
    cStr = createCStrFromInput(cStr, size, capacity, std::cin);
    if (size == 0)
    {
      std::cerr << "Empty string" << '\n';
      delete[] cStr;
      return 1;
    }
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete[] cStr;
    return 1;
  }

  std::cout << std::boolalpha << isMathExpr(cStr) << '\n';

  delete[] cStr;

  return 0;
}
