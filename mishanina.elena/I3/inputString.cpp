#include "inputString.h"

char* inputString(size_t &capacity, std::istream& input)
{
  size_t size = 0;
  char* cstring = new char[capacity];
  cstring[0] = '\0';
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      char* newstr = new char[capacity + 20];
      for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
      {
        *j = *i;
      }
      cstring = newstr;
      capacity += 20;
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');
  cstring[size - 1] = '\0';
  return cstring;
}
