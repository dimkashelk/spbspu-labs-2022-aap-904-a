#include "makeNewStringWithoutRepeat.h"
#include <cstddef>
#include <cstring>

char* copyString(char* destination, const char* source, size_t index)
{
  size_t source_lenght = strlen(source);
  for (size_t i = 0; i < source_lenght; i++)
  {
    destination[index + i] = source[i];
  }
  destination[source_lenght + index] = '\0';
  return destination;
}

char* removeDuplicateLetters(char* destination)
{
  size_t total_len = strlen(destination);
  for (size_t i = 0; i < total_len; i++)
  {
    for (size_t j = i + 1; j < total_len; j++)
    {
      if (destination[i] == destination[j])
      {
        total_len--;
        for (size_t k = j; k < total_len - 1; k++)
        {
          destination[k] = destination[k + 1];
        }
        j--;
      }
    }
  }
  destination[total_len] = '\0';
  return destination;
}

char* makeNewStringWithoutRepeat(char* destination, const char* source1, const char* source2)
{
  size_t str_len1 = strlen(source1);

  destination = copyString(destination, source1, 0);
  destination = copyString(destination, source2, str_len1);
  destination = removeDuplicateLetters(destination);

  return destination;
}
