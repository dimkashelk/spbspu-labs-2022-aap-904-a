#include <iostream>
#include "formStringFromFirstWithoutSecond.h"
#include "formStringFromOtherSymbols.h"
int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (size > 0)
  {
    cstring[size - 1] = '\0';
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
    std::cout << formStringFromOtherSymbols(result1, cstring, cstring2) << "\n";
    delete[] result1;
  }
  catch (std::bad_alloc const& e)
  {
    std::cerr << "Fail" << "\n";
    return 3;
  }
  try
  {
    char *result2 = new char[size + 1];
    std::cout << formStringFromFirstWithoutSecond(result2, cstring, cstring2) << "\n";
    delete[] result2;
  }
  catch (std::bad_alloc const& e)
  {
    std::cerr << "Fail" << "\n";
    return 3;
  }

  delete[] cstring;
  return 0;
}
