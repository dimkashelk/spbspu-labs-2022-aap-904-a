#include "readArray.h"
#include <iostream>
#include <fstream>
int *readArray(std::string fn)
{
  std::ifstream in(fn);
  size_t size = 0;
  in >> size;
  if (!in)
  {
   throw std::runtime_error("meh");
  }
  int *array3 = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    in >> array3[i];
    if (!in)
    {
      std::cout << "Error again...";
      delete[] array3;
      throw;
    }
  }
  return array3;
}
