#include <iostream>
#include "isexpression.h"

char *makeNewCapacityCString(char *cstring, size_t &capacity, size_t size)
{
  char *newstring = new char[capacity + 20];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  capacity += 20;
  return newstring;
}

int main()
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  size_t size = 0;
  cstring[0] = '\0';
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char *newCString = makeNewCapacityCString(cstring, capacity, size);
        delete[] cstring;
        cstring = newCString;
        newCString = nullptr;
      }
      catch (const std::exception &e)
      {
        std::cerr << e.what() << "\n";
        delete[] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  if (cstring[0] == '\0' || cstring[0] == '\n')
  {
    std::cout << "Error while reading the string \n";
    delete[] cstring;
    return 2;
  }
  cstring[size - 1] = '\0';
  char* new_cstring = nullptr;
  try
  {
    new_cstring =cstring;
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  std::cout << std::boolalpha << isExpression(new_cstring) << "\n";
  delete[] cstring;
}
