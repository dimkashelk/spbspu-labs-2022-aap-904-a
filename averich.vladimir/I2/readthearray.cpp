#include "readthearray.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
int* readTheArray(std::istream& in, size_t& sizeOfFileArray, int* fileArray, const size_t maxSize)
{
  if (sizeOfFileArray != maxSize)
  {
    for (size_t i = 0; i < sizeOfFileArray; i++)
    {
      in >> fileArray[i];
      if (!in)
      {
        std::cerr << ("Error reading file");
      }
    }
  }
  return fileArray;
}

