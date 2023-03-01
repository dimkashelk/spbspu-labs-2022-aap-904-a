#include "most_common_characters.h"
#include <cstddef>
#include <algorithm>
#include <string.h>

char* printMostCommonCharacters(char* destination, const char* source)
{
  for (size_t t = 0; t <= 3; t++)
  {
    destination[t] = 0;
  }
  char k = 0;
  while (k < 3)
  {
    size_t max = 0;
    for (char t = 127; t > 1; t--)
    {
      size_t l = 0;
      if ((k == 1) & (t == destination[2] - 0))
      {
        continue;
      }
      else
      {
        if ((k == 2) & ((t == destination[2] - 0) || (t == destination[1] - 0)))
        {
          continue;
        }
        else
        {
          for (size_t i = 0; i < strlen(source); i++)
          {
            if (t == source[i] - 0)
            {
              l++;
            }
          }
        }
      }
      switch (k)
      {
        case 0:
          if (l >= max)
          {
            destination[2] = (char) t;
            max = l;
          }
          break;
        case 1:
          if (l >= max)
          {
            destination[1] = (char) t;
            max = l;
          }
          break;
        case 2:
          if (l >= max)
          {
            destination[0] = (char) t;
            max = l;
          }
          break;
      }
    }
    k++;
  }
  std::swap(destination[0], std::min(destination[0], std::min(destination[1], destination[2])));
  std::swap(destination[2], std::max(destination[2], std::max(destination[1], destination[0])));
  return destination;
}
