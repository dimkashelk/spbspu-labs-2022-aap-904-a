
#include "my_String.h"
#include <my_ext_String.h>

char* makeMyString(size_t &size, size_t &capacity, std::istream &input)
{
  char* my_string = new char[capacity];
  my_string[0] = '\n';

  input >> std::noskipws;
  do
  {
    if (size + 1 == capacity)
    {
      my_string[size] = '\0';
      char* newstr = extendMyString(my_string, capacity);
      delete[] my_string;
      my_string = newstr;
    }
    input >> my_string[size];
  }
  while (input && my_string[size++] != '\n');

  if (my_string[0] != '\n')
  {
    my_string[size - 1] = '\0';
  }

  return my_string;
}
