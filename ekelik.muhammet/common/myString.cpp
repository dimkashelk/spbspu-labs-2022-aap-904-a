#include "myString.h"
#include <myExtString.h>

char* makeMyString(size_t& size, size_t& capacity, std::istream& input)
{
  char* myString = new char[capacity];
  myString[0] = '\0';

  input >> std::noskipws;
  do
  {
    if (size + 1 >= capacity)
    {
      capacity *= 2;
      char* newstr = new char[capacity];
      std::memcpy(newstr, myString, size);
      delete[] myString;
      myString = newstr;
    }
    input >> myString[size];
  }
  while (input && myString[size++] != '\n');

  if (myString[0] == '\n')
  {
    myString[0] = '\0';
    size = 0;
  }
  else
  {
    myString[size - 1] = '\0';
  }
  return myString;
}
