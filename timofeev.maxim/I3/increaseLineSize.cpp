#include "increaseLineSize.h"
#include <limits>
#include <stdexcept>
char *str_input(std::istream &str, size_t &in_size)
{
  const size_t max_size = std::numeric_limits< size_t >::max();
  size_t capasity = 10;
  size_t size = 0;
  char *cstring = new char[capasity];
  str >> std::noskipws;
  do
  {
    if (size == capasity)
    {
      if (capasity == max_size)
      {
        delete [] cstring;
        throw std::runtime_error("Size of string more than max_size");
      }
      try
      {
        char *newstr = new char[capasity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capasity += 20;
      }
      catch (...)
      {
        delete [] cstring;
        throw std::runtime_error("Memory error");
      }
    }
    str >> cstring[size];
  }
  while (str && cstring[size++] != '\n');
  if (!str || !size)
  {
    delete [] cstring;
    throw std::runtime_error("Input error");
  }
  cstring[size - 1] = '\0';
  in_size = size;
  return cstring;
}
