#include "makecstring.hpp"
#include <iostream>
#include <cstring>

char *makeCString(char *c_string, size_t &size, size_t &capacity, std::istream &input)
{
  input >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      char *newstr = new char[capacity + 10];
      c_string[size] = '\0';
      std::strcpy(newstr, c_string);
      delete[] c_string;
      c_string = newstr;
      capacity += 10;
      std::cout << c_string << "!\n";
    }
    input >> c_string[size];
  }
  while (input && c_string[size++] != '\n');

  return c_string;
}
