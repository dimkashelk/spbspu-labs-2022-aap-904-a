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
    throw std::logic_error("Empty file");
  }
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      throw std::logic_error("Error input");
      in.close();
    }
  }
  return fileArray;
}
