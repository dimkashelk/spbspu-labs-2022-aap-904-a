#include "readthearray.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <cctype>
std::istream& readTheArray(std::istream& in, size_t& sizeOfFileArray, int* fileArray, size_t maxSize)
{
  if (sizeOfFileArray < maxSize)
  {
    for (size_t i = 0; i < sizeOfFileArray; i++)
    {
      in >> fileArray[i];
      if (in.bad())
      {
        return in;
      }
    }
  }
  else
  {
    std::cout << "Error: invalid size of array" << '\n';
    return in;
  }
}
