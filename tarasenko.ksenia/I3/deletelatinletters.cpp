#include "deletelatinletters.hpp"

char * deleteLatinLetters(char * res_str1, const char * cstring)
{
  auto j = res_str1;
  for (auto i = cstring; *i != '\0'; i++)
  {
    if (!(((*i >= 'A') && (*i <= 'Z')) || ((*i >= 'a') && (*i <= 'z'))))
    {
      *j = *i;
      ++j;
    }
  }
  *j = '\0';
  return res_str1;
}
