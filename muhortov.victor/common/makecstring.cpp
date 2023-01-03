#include "makecstring.hpp"
#include <iostream>
#include <cstring>

char *makeCString(char *c_string, size_t &size, size_t &capacity, std::istream &input)
{
  input >> std::noskipws;

  do
  {
    if (size + 1 == capacity)
    {
      char *newstr = new char[capacity + 10];
      c_string[capacity - 1] = '\0';
      std::strcpy(newstr, c_string);
      delete[] c_string;
      c_string = newstr;
      capacity += 10;
    }
    input >> c_string[size];
  }
  while (input && c_string[size++] != '\n');

  return c_string;
}
