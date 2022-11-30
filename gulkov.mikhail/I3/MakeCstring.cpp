#include "MakeCstring.hpp"
#include <stdexcept>
#include <cstddef>
#include <istream>

char *make_cstring(char *cstring, size_t &size, size_t &capacity, std::istream &input)
{
  input >> std::noskipws;

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
      catch (const std::bad_alloc &e)
      {
        throw std::runtime_error("Error while creating cstring(array)!");
      }
    }

    input >> cstring[size];

  } while (input && cstring[size++] != '\n');

  cstring[size - 1] = '\0';

  return cstring;
}
