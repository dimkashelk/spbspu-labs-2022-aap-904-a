#include "most_common_characters.h"
#include <iostream>

char* printMostCommonCharacters(char* destination, const char* source)
{
  size_t ascii[129] = {0};
  size_t i = 0;
  while (source[i] != '\0')
  {
    ascii[static_cast< size_t >(source[i])]++;
    i++;
  }
  size_t idx1 = 128;
  size_t idx2 = 128;
  size_t idx3 = 128;
  for (i = 0; i < 128; i++)
  {
    if (ascii[i] > ascii[idx1])
    {
      idx3 = idx2;
      idx2 = idx1;
      idx1 = i;
    }
    else if (ascii[i] > ascii[idx2])
    {
      idx3 = idx2;
      idx2 = i;
    }
    else if (ascii[i] > ascii[idx3])
    {
      idx3 = i;
    }
  }
  destination[0] = char(idx1);
  destination[1] = char(idx2);
  destination[2] = char(idx3);
  size_t j = 0;
  char tmp = 0;
  for (i = 0; i < 3 - 1; i++)
  {
    for (j = 0; j < 3 - i -1; j++)
    {
      if (destination[j] > destination[j + 1])
      {
        tmp = destination[j];
        destination[j] = destination[j + 1];
        destination[j + 1] = tmp;
      }
    }
  }
  destination[3] = '\0';
  return destination;
}
