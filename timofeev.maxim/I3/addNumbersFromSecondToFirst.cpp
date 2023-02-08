#include "addNumbersFromSecondToFirst.h"
#include <cctype>
char *addNumbers(char *destination, const char *source1, const char *source2)
{
  char *j = destination;
  for (const char *i = source1; *i != '\0'; i++)
  {
    *j = *i;
    ++j;
  }
  for (const char *i = source2; *i != '\0'; i++)
  {
    if (std::isdigit(*i))
    {
      *j = *i;
      ++j;
    }
  }
  size_t size = 0;
  for (char *p = destination; *p != '\0'; p++)
  {
    size++;
  }
  size++;
  destination[size] = '\0';
  return destination;
}
