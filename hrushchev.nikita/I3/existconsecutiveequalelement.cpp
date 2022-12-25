#include "existconsecutiveequalelement.hpp"
#include <cstddef>

bool exist_consecutive_equal_element(const char* source)
{
  if((source == nullptr) || (source[0] == '\0'))
  {
    return false;
  }

  size_t i = 0;
  while (source[i + 1] != '\0')
  {
    if (source[i] == source[i + 1])
    {
      return true;
    }
    i++;
  }
  return false;
}
