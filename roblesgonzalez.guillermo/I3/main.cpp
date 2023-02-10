#include <iostream>
#include <cstddef>
#include <cstring>
#include <ctype.h>
#include <limits.h>
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"

int main()
{
  size_t cap = 10;
  char* cstring = new char[cap];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == cap - 1)
    {
      try
      {
        cstring[cap - 1] = '\0';
        char* newstr = new char[cap + 20];
        std::strcpy(newstr, cstring);
        delete [] cstring;
        cstring = newstr;
        cap += 20;
      }
      catch (...)
      {
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  if (size == 0)
  {
    std::cerr << "Empty string\n";
    delete [] cstring;
    return 1;
  }
  else
  {
    cstring[size - 1] = '\0';
  }
  char* destination = nullptr;
  try
  {
    destination = new char[size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cout << e.what() << '\n';
    delete [] cstring;
    return 1;
  }
  removeDuplicateSpaces(destination, cstring);
  removeDigits(destination, destination);
  std::cout << destination << '\n';
  delete [] cstring;
  delete [] destination;
  return 0;
}
