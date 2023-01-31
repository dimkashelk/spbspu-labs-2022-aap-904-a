#include "newstring.h"
#include <algorythm>
#include <cctype>
#include <iostream>

char * potapova::addThreeMostCommonSymbols(char * destination1, const char * source)
{
  char symbols[256] = {0};
  char * k = destination1;
  for(int i = 0; *k[i]; i++)
  {
    symbols[*k[i]]++;
  }
  int max = 0;
  for(int i = 1; i < 256; i++)
  {
    if(symbols[i] > symbols[max])
    {
      max = i;
    }
  }
  int predmax = 0;
  for(int i = 1; i < 256; i++)
  {
    if(symbols[i] > symbols[predmax] && symbols[i] < symbols[max])
    {
      predmax = i;
    }
  }
  int prepredmax = 0;
  for(int i = 1; i < 256; i++)
  {
    if(symbols[i] > symbols[prepredmax] && symbols[i] < symbols[predmax])
    {
      prepredmax = i;
    }
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
  std::sort(*j; *j != '\0'; j++);
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
