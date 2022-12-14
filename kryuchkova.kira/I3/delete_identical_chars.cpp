#include "delete_identical_chars.h"
#include <cctype>

char *delete_identical_chars(size_t size_first, const char *cstring_first, size_t size_second, const char *cstring_second)
{
  size_t k = 0;
  bool identical_chars = false;
  char * cstring_third = new char[size_first];

  for(size_t i = 0; i < size_first; i++)
  {
    for(size_t j = 0; j < size_second; j++)
    {
      if (cstring_first[i] == cstring_second[j])
      {
        identical_chars = true;
        break;
      }
    }

    if (!identical_chars)
    {
      cstring_third[k]=cstring_first[i];
      k++;
    }

    identical_chars = false;
  }

  cstring_third[k] = '\0';
  return cstring_third;
  delete [] cstring_third;
}
