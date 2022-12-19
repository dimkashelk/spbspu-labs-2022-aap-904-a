#include <iostream>
#include <cstddef>
#include "countdifferentletters.h"
#include "findrepeatedsymbols.h"

int main()
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  size_t size = 0;
  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char * newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
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
  if (!std::cin && !size)
  {
    std::cout << "error";
    delete[] cstring;
    return 1;
  }
  cstring[size - 1] = '\0';
  std::cout << cstring << "\n";
  std::cout << countDifferentLetters(cstring) << '\n';
  std::cout << findRepeatedSymbols(cstring) << '\n';
  delete [] cstring;
}