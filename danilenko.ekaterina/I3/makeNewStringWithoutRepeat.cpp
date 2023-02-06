#include "makeNewStringWithoutRepeat.h"
#include <iostream>
#include <cctype>
#include <cstddef>

char* makeNewStringWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  size_t new_element = 0;
  bool match = false;
  
  for (size_t i = 0; source1[i] != '\0'; i++)
  {
    match = false;
    for (size_t j = 0; source2[j] != '\0'; j++)
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
  for (size_t i = 0; source2[i] != '\0'; i++)
  {
    match = false;
    for (size_t j = 0; source1[j] != '\0'; j++)
    {
      if (source2[i] == source1[j])
      {
        match = true;
        break;
      }
    }
    if (match == false)
    {
      destination[new_element++] = source2[i];
    }
  }

  destination[new_element] = '\0';
  return destination;
}
