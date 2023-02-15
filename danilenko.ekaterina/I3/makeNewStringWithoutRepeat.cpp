#include "makeNewStringWithoutRepeat.h"
#include <cstddef>
#include <cstring>

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
  size_t str_len2 = strlen(source2);
  size_t total_len = str_len1 + str_len2;

  for (size_t i = 0; i < str_len1; i++)
  {
    destination[i] = source1[i];
  }
  for (size_t j = 0; j < str_len2; j++)
  {
    destination[str_len1 + j] = source2[j];
  }
  destination[total_len] = '\0';
  destination = removeDuplicateLetters(destination);

  return destination;
}
