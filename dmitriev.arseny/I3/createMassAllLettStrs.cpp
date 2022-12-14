#include "createMassAllLettStrs.h"
#include <cstddef>

void defDiffLett(const char* cStr, bool* letExist)
{
  for (size_t i = 0; cStr[i] != '\0'; i++)
  {
    if (int(cStr[i]) >= 97 && int(cStr[i]) <= 122)
    {
      letExist[int(cStr[i]) - 97] = 1;
    }
    if (int(cStr[i]) >= 65 && int(cStr[i]) <= 90)
    {
      letExist[int(cStr[i]) - 65] = 1;
    }
  }
}

char* createMassAllLettStrs(char* cStrAllLett, const char* cStr1, const char* cStr2)
{
  bool letExist[26];
  size_t totalDiffLett = 0;

  for (size_t i = 0; i < 26; i++)
  {
    letExist[i] = 0;
  }

  defDiffLett(cStr1, letExist);
  defDiffLett(cStr2, letExist);

  for (size_t i = 0, j = 0; i < 26; i++)
  {
    if (letExist[i])
    {
      cStrAllLett[j++] = char(i + 65);
      totalDiffLett = j;
    }
  }
  cStrAllLett[totalDiffLett] = '\0';

  return cStrAllLett;
}
