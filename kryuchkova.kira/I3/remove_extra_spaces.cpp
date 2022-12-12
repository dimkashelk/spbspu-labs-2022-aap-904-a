#include "remove_extra_spaces.h"
#include <cctype>

char *remove_extra_spaces(size_t size, const char *cstring)
{
  size_t n = 0;
  size_t k = 0;
  char * cstring_2 = new char[size];

  while (std::isspace(cstring[n]))
  {
    n++;
  }

  for (size_t i = n; i < size; i++)
  {
    if (!(std::isspace(cstring[i]) && cstring[i] == cstring[i - 1]))
    {
      cstring_2[k] = cstring[i];
      k++;
    }
  }

  if (std::isspace(cstring_2[k - 1]))
  {
    k--;
  }

  cstring_2[k] = '\0';
  return cstring_2;
  delete [] cstring_2;
}
