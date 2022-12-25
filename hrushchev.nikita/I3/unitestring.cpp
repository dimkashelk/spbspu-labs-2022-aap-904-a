#include "unitestring.hpp"
#include <cstddef>

char* unite_string(char* destination, const char* source1, const char* source2)
{
  if ((source1 == nullptr) || (source2 == nullptr))
  {
    return nullptr;
  }

  size_t i = 0;
  size_t j = 0;
  while ((source1[i] != '\0') && (source2[i] != '\0'))
  {
    destination[j++] = source1[i];
    destination[j++] = source2[i];
    i++;
  }

  if (source1[i] != '\0')
  {
    size_t j = 2 * i;
    while (source1[i] != '\0')
    {
      destination[j++] = source1[i++];
    }
  }
  else if (source2[i] != '\0')
  {
    size_t j = 2 * i;
    while (source2[i] != '\0')
    {
      destination[j++] = source2[i++];
    }
  }
  return destination;
}
