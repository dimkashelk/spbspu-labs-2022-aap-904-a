#include "newstring.h"
#include <algorithm>
#include <cctype>
#include <iostream>

char * potapova::addThreeMostCommonSymbols(char * destination1, const char * source)
{
  char * j = destination1;
  for (const char * i = source, *i != '\0', i++)
  {
    
  }
}
char * potapova::addAllLatinLetters(char * destination2, const char * source1, const char * source2)
{
  char * j = destination2;
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
  }
  for(const char * i = 0; *i != '\0'; i++)
  {
    for(const char * j = i + 1; *j != '\0'; j++)
    {
      if(destination2[i] > destination2[j])
      {
        char temp = destination2[i];
        destination2[i] = destination2[j];
        destination2[j] = temp;
      }
    }
  }
  return destination2;
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
