#include "inputString.h"

char* inputString(char* cstring, size_t &capacity, std::istream& input)
{
  size_t size = 0;
  input >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char* newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        {
          *j = *i;
        }
        delete[] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete[] cstring;
        throw;
      }
    }
    input >> cstring[size];
  }
  while (input && cstring[size++] != '\n');
  capacity = size;
  return cstring;
}
