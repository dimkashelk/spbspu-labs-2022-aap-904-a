#include "hasItTheSameSimbols.h"

bool hasItTheSameSimbols(const char* cstring1, const char* cstring2)
{
  for (size_t i = 0; i < strlen(cstring1); i++)
  {
    for (size_t j = 0; j < strlen(cstring2); j++)
    {
      if (cstring1[i] == cstring2[j])
      {
        return true;
      }
    }
  }
  return false;
}
