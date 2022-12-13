#include "hasRepeatingElements.h"
#include <cstddef>
#include <cctype>
bool hasRepeatingElements(const char *source)
{
  size_t index1 = 0;
  size_t index2 = 1;

  while(source[index1] != '\0')
  {
    while(source[index2] != '\0')
    {
      if(source[index1]==source[index2])
      {
      return true;
      }
      index2 ++;
    }
    index1 ++;
    index2 = index1+1;
  }
  return false;
}
bool hasRepeatingElements(const char *source1, const char *source2)
{
  size_t index1 = 0;
  size_t index2 = 0;

  while(source1[index1] != '\0')
  {
    while(source2[index2] != '\0')
    {
      if(source1[index1] == source2[index2])
      {
      return true;
      }
      index2 ++;
    }
    index1 ++;
    index2 = 0;
  }
  return false;
}
