#include "readthearray.hpp"
#include "istriplet.hpp"
#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
int* readTheArray(std::istream& in, size_t& sizeOfFileArray, int* fileArray)
{
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      throw std::length_error("Error reading file");
    }
  }
  return fileArray;
}

