#include "removeextraspaces.h"
char *remove_extra_spaces(char *destination, const char *source, size_t source_size)
{
  char * str = new char[source_size];
  size_t size = 0;
  size_t d = 0;
  while (source[d] == ' ')
  {
    d++;
  }
  while (source[d])
  {
    if (source[d] == ' ')
    {
      while (source[d] == ' ')
      {
        d++;
      }
      str[size] = ' ';
      size++;
    }
    else
    {
      str[size] = source[d];
    }
    d++;
  }
  while (str[size - 1] == ' ')
  {
    size--;
  }
  str[size] = '\0';
  for (size_t k = 0; k < size; k++)
  {
    destination[k] = str[k];
  }
  delete[] str;
  return destination;
}
