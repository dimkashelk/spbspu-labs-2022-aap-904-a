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
  if (in.eof())
  {
    throw std::runtime_error("Empty file");
  }
  if (sizeOfFileArray == 0)
  {
    throw std::logic_error("File with empty array");
  }
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      std::cerr << "Invalid input" << std::endl;
      in.close();
    }
  }
  return fileArray;
}
