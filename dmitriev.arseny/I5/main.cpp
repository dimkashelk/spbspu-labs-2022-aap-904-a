#include <iostream>
#include <cstddef>
#include "isExpression.h"

int main()
{
  size_t capacity = 10;
  size_t size = 0;
  char inp = '\0';
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

  std::cin >> std::noskipws;

  for (std::cin >> inp; (std::cin && inp) && (inp != '\n'); std::cin >> inp)
  {
    if (size == capacity)
    {
      capacity = capacity + 10;
      char* dupStr = nullptr;
      try
      {
        dupStr = new char[capacity];
      }
      catch (const std::bad_alloc& e)
      {
        std::cout << e.what() << '\n';
        delete[] cStr;
        return 1;
      }
      for (size_t i = 0; i < size; i++)
      {
        dupStr[i] = cStr[i];
      }
      delete[] cStr;
      cStr = dupStr;
      dupStr = nullptr;
    }
    cStr[size++] = inp;
  }

  if (size == 0)
  {
    std::cerr << "Empty string" << '\n';
    delete[] cStr;
    return 1;
  }

  cStr[size] = '\0';

  std::cout << std::boolalpha << isExpr(cStr) << '\n';

  return 0;
}