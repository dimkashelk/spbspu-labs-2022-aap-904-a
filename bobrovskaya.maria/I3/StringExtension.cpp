#include "StringExtension.h"

char* stringExtension(char *source1, size_t &capacity, size_t size)
{
  char *newstr = new char[capacity + 20];
  for (auto i = source1, j = newstr; i != source1 + size; i++, j++)
  {
    *j = *i;
  }
  capacity += 20;
  return newstr;
}
