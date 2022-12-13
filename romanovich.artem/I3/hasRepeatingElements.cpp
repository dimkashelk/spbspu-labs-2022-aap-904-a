#include "hasRepeatingElements.h"
#include <cctype>
#include <iostream>
bool hasRepeatingElements(const char *source)
{
  size_t index1 = 0;
  size_t index2 = 1;

  while(source[index1] != '\0')
  {
    while(source[index2] != '\0')
    {
      //std::cout << source[index1] << " " << source[index2] <<" "<< (source[index1]==source[index2]) << "\n";
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