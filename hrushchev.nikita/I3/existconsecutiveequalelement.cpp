#include "existconsecutiveequalelement.hpp"
#include <cstddef>

bool exist_consecutive_equal_element(const char* source)
{
  if ((source == nullptr) || (source[0] == '\0'))
  {
    return false;
  }

  for (auto i = source; *(i + 1) != '\0'; i++)
  {
    if (*i == *(i + 1))
    {
      return true;
    }
  }
  return false;
}
