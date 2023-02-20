#include "makeNewStringWithoutRepeat.h"
#include <cstddef>

char* copyElementsWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  size_t new_element = 0;
  bool match = false;
  for (size_t i = 0; source1[i] != '\0'; i++)
  {
    match = false;
    for (size_t j = 0; source2[j] != 0; j++)
    {
      if (source1[i] == source2[j])
      {
        match = true;
        break;
      }
    }
    if (match == false)
    {
      destination[new_element++] = source1[i];
    }
  }
  destination[new_element] = '\0';
  return destination;
}

char* makeNewStringWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  copyElementsWithoutRepeat(destination, source1, source2);
  size_t dest_lenght = 0;
  for (size_t i = 0; destination[i] != '\0'; i++)
  {
    dest_lenght++;
  }
  copyElementsWithoutRepeat(destination + dest_lenght, source2, source1);
  return destination;
}
