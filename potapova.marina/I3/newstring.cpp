#include "newstring.h"
#include <algorithm>
#include <cctype>
#include <iostream>

char * potapova::addThreeMostCommonSymbols()
{
  for (auto)
}
char * potapova::addAllLatinLetters(char * destination , const char * source1, const char * source2)
{
  char * j = destination;
  for (const char * i = source1; *i != '\0'; i++)
  {
    if (std::isalpha(*i))
    {
      *(j + 1) = '\0';
      *j = *i;
      j++;
    }
  }
  for (const char * i = source2; *i != '\0'; i++)
  {
    if (std::isalpha(*i))
    {
      *(j + 1) = '\0';
      *j = *i;
      j++;
    }
  std::sort(destination);
  }

  return destination;
}
potapova::receiveStringTypeC()
{
  size_t capasity = 10;
  char * cstring = new char[capasity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do {
    if (size == capasity) {
      try {
        char * newstr = new char[capasity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j) {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capasity += 20;
      } catch(const std::exception & e) {
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  } while (std::cin && cstring[size++] != '\n');
  cstring[size - 1] = '\0';

  std::cout << cstring << "\n";
  delete [] cstring;

}
