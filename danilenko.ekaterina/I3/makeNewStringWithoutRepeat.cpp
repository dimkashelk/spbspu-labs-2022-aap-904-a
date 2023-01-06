#include "makeNewStringWithoutRepeat.h"
#include <iostream>
#include <cctype>
#include <cstddef>

char* makeNewStringWithoutRepeat(char* destination, const char* source1, const char* source2, size_t size)
{
  size_t new_elements = 0;
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if (std::tolower(source1[i]) == std::tolower(source2[j]))
      {
        break;
      }
      else if (j == size - 1)
      {
        destination[new_elements++] = source1[i];
      }
    }
  }

  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if (std::tolower(source2[i]) == std::tolower(source1[j]))
      {
        break;
      }
      else if (j == size - 1)
      {
        destination[new_elements++] = source2[i];
      }
    }
  }
  destination[new_elements] = '\0';
  return destination;
}
