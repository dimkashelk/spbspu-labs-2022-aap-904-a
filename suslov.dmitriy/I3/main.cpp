#include <iostream>
#include "details.h"
#include "formStringFromFirstWithoutSecond.h"
#include "formStringFromOtherSymbols.h"
int main()
{
  size_t size;
  try
  {
    char *cstring = scanStr(size, std::cin);
  }
  catch (std::bad_alloc &e)
  {
    std::cerr << "Few memory" << '\n' << e.what();
    return 3;
  }
  if (size == 0 || size == 1)
  {
    std::cerr << "Empty input" << '\n';
    delete[] cstring;
    return 2;
  }
  char cstring2[] = "qwerty";
  size_t size2 = sizeof cstring2;
  try
  {
    char *result1 = new char[size + size2 + 1];
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Few memory" << '\n' << e.what();
    return 3;
  }
  std::cout << formStringFromOtherSymbols(result1, cstring, cstring2) << "\n";
  delete[] result1;

  try
  {
    char *result2 = new char[size + 1];
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Few memory" << '\n' << e.what();
    return 3;
  }
  std::cout << formStringFromFirstWithoutSecond(result2, cstring, cstring2) << "\n";
  delete[] result2;
  delete[] cstring;
  return 0;
}
