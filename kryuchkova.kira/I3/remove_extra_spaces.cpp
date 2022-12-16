#include "remove_extra_spaces.h"
#include <cctype>
#include <cstddef>
#include <iostream>

char *remove_extra_spaces(char *destination, const char *cstring)
{
  size_t n = 0;
  size_t k = 0;

  while (std::isspace(cstring[n]))
  {
    n++;
  }

  size_t capacity = 10;
  while (cstring[n])
  {
    if (!(std::isspace(cstring[n]) && cstring[n] == cstring[n - 1]))
    {
      if (k == capacity)
      {
        try
        {
          char *newstr = new char[capacity + 20];
          for (auto i = destination, j = newstr; i != destination + k; ++i, ++j)
          {
            *j = *i;
          }
          delete[] destination;
          destination = newstr;
          capacity += 20;
        }
        catch (...)
        {
          delete[] destination;
          throw;
        }
      }
      destination[k] = cstring[n];
      k++;
    }
    n++;
  }

  if (std::isspace(destination[k - 1]))
  {
    k--;
  }
  destination[k] = '\0';
  return destination;
}
