#include <iostream>
#include <cstring>
#include "formStringFromFirstWithoutSecond.h"
#include "formStringFromOtherSymbols.h"
char *expandString(char *oldString, size_t newSize)
{
  char *newStr = new char[newSize];
  strcpy(newStr, oldString);
  delete[] oldString;
  newStr[newSize - 1] = '\0';
  return newStr;
}
char *scanStr(size_t &length, std::istream &in)
{
  size_t capacity = 10;
  char *cstring = nullptr;
  try
  {
    cstring = new char[capacity];
  }
  catch (const std::bad_alloc &)
  {
    return nullptr;
  }
  cstring[capacity - 1] = '\0';
  length = 0;
  in >> std::noskipws;
  do
  {
    if (length + 1 == capacity)
    {
      try
      {
        capacity += 20;
        cstring = expandString(cstring, capacity);
      }
      catch (const std::bad_alloc &)
      {
        delete[] cstring;
        return nullptr;
      }
    }
    in >> cstring[length];
  } while (std::cin && cstring[length++] != '\n');
  if (length > 0)
  {
    cstring[length - 1] = '\0';
  }
  return cstring;
}
int main()
{
  size_t size;
  char *cstring = scanStr(size, std::cin);
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
  catch (const std::bad_alloc &e)
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
  catch (const std::bad_alloc &e)
  {
    std::cerr << "Fail" << "\n";
    return 3;
  }
  delete[] cstring;
  return 0;
}
