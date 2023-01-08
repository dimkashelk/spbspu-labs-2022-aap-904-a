#include "details.h"
#include <cstring>
char *expandString(char *oldString, size_t newSize)
{
  char *newStr = new char[newSize];
  std::strcpy(newStr, oldString);
  newStr[newSize - 1] = '\0';
  return newStr;
}
char *scanStr(size_t &length, std::istream &in)
{
  size_t capacity = 10;
  char *cstring = new char[capacity];
  cstring[capacity - 1] = '\0';
  length = 0;
  in >> std::noskipws;
  do
  {
    if (length + 1 == capacity)
    {
      try
      {
        capacity += 20;
        char *newCstring = expandString(cstring, capacity);
      }
      catch (const std::bad_alloc &)
      {
        delete[] ctring;
        throw;
      }
      delete[] cstring;
      cstring = newCstring;
    }
    in >> cstring[length];
  }
  while (std::cin && cstring[length++] != '\n');
  if (length > 0)
  {
    cstring[length - 1] = '\0';
  }
  return cstring;
}
