#include "readthearray.hpp"
#include "istriplet.hpp"
#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
int* readTheArray(std::string fileName, size_t& sizeOfFileArray, int* fileArray)
{
  std::ifstream in(fileName);
  if (in.eof())
  {
    throw "Error";
  }
  in >> sizeOfFileArray;
  if (!in)
  {
    throw "Error";
  }
  if (sizeOfFileArray == 0)
  {
    throw "Error";
  }
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      throw "Error";
    }
  }
  return fileArray;
}
