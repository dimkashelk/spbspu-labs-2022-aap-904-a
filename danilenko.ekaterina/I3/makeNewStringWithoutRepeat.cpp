#include "makeNewStringWithoutRepeat.h"
#include <cstddef>

bool copyElementsWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  bool match = false;
  char* d = destination;
  for (const char* i = source1; *i != '\0'; i++)
  {
    match = false;
    for (const char* j = source2; *j != '\0'; j++)
    {
      if (*i == *j)
      {
        match = true;
        break;
      }
    }
    if (match == false)
    {
      *d = *i;
      ++d;
    }
  }
  *d = '\0';
  return false;
}

char* makeNewStringWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  copyElementsWithoutRepeat(destination, source1, source2);
  size_t dest_lenght = 0;
  for (char* i = destination; *i != '\0'; i++)
  {
    dest_lenght++;
  }
  copyElementsWithoutRepeat(destination + dest_lenght, source2, source1);
  return destination;
}
