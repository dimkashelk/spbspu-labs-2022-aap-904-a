#include "isDigitInStr.h"
bool isDigitInStr(const char *str)
{
  for (auto i = str; *i != '\0'; ++i)
  {
    if (std::isdigit(*i))
    {
      return true;
    }
  }
  return false;
}
