#include "input_string.h"
#include "golden_ratio.h"
#include "extend_string.h"
char * inputStr(std::istream & in, size_t & size, size_t & capacity)
{
  capacity = 10;
  char * str_1 = new char[capacity];
  size = 0;
  in >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        size_t new_capacity = goldenRatio(capacity);
        char * new_str = extendString(str_1, capacity, new_capacity);
        delete [] str_1;
        str_1 = new_str;
        capacity = new_capacity;
      }
      catch (...)
      {
        delete [] str_1;
        throw;
      }
    }
    in >> str_1[size];
  }
  while (in && str_1[size++] != '\n');
  if (!in && !size)
  {
    delete[] str_1;
    throw std::runtime_error("error");
  }
  str_1[size - 1] = '\0';
  return str_1;
}
