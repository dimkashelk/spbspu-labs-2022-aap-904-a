#include "makecstring.hpp"
#include <extendcstring.hpp>

char *makeCString(size_t &size, size_t &capacity, std::istream &input)
{
  char *c_string = new char[capacity];
  c_string[0] = '\n';

  input >> std::noskipws;
  do
  {
    if (size + 1 == capacity)
    {
      c_string = extendCString(c_string, capacity);
    }
    input >> c_string[size];
  }
  while (input && c_string[size++] != '\n');

  if (c_string[0] != '\n')
  {
    c_string[size - 1] = '\0';
  }

  return c_string;
}
