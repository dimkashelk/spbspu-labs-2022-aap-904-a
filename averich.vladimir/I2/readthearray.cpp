#include "readthearray.hpp"
#include "istriplet.hpp"
#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
int* readTheArray(std::string fileName, size_t& sizeOfFileArray, int* fileArray)
{
  std::ifstream in(fileName);
  in >> sizeOfFileArray;
  if (sizeOfFileArray == 0)
  {
    throw "Invalid size of array";
  }
  if (in.eof())
  {
      throw "Empty array";
      in.close();
  }
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      throw "The array is not equals to size of it";
      in.close();
    }
  }
  return fileArray;
}
