#include "MakeString.hpp"

char *makeString(char *destination, size_t &size, size_t &capacity, std::istream &input)
{
  input >> std::noskipws;

  do
  {
    if (size == capacity)
    {
      char *newstr = new char[capacity + 10];
      for (auto i = destination, j = newstr; i != destination + size; ++i, ++j)
      {
        *j = *i;
      }
      delete[] destination;
      destination = newstr;
      capacity += 10;
    }
    input >> destination[size];
  }
  while (input && destination[size++] != '\n');

  return destination;
}
