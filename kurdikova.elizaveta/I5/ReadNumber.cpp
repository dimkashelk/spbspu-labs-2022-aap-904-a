#include "ReadNumber.h"
#include <cstddef>
#include <cstring>
#include <valarray>

char* readNumber(std::istream& in)
{
  size_t size = 0;
  size_t capacity = 4;
  char* number = new char[capacity];
  in >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        capacity *= 2;
        char* newstr = new char[capacity];
        number[size] = '\0';
        for (auto i = number, j = newstr; i != number + size; i++, j++)
        {
          *j = *i;
        }
        delete[] number;
        number = newstr;
      }
      catch (const std::bad_alloc& e)
      {
        delete[] number;
        throw e;
      }
    }
    in >> number[size++];
  }
  while (in && number[size - 1] != '\n');
  if (size <= 1)
  {
    delete[] number;
    throw std::invalid_argument("Nothing was entered!\n");
  }
  number[size - 1] = '\0';
  return number;
}
