#include "readthearray.hpp"
#include "istriplet.hpp"
#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
int readTheArray(std::string fileName)
{
  std::ifstream in(fileName);
  if (in.eof())
  {
   throw std::logic_error("Error: file is empty");
   return 1;
  }
  size_t sizeOfFileArray = 0;
  in >> sizeOfFileArray;
  if (!in)
  {
   throw std::logic_error("Error: invalid input");
   return 1;
  }
  else if (sizeOfFileArray == 0)
  {
   throw std::logic_error("Error: incorrect size of array");
   return 1;
  }
  int * fileArray = new int[sizeOfFileArray];
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      throw std::logic_error("Error: check the file");
      in.close();
      delete[] fileArray;
    }
  }
  std::cout << "Count of triplets: " << isTriplet(fileArray, sizeOfFileArray) << " in the file array" << std::endl;
  sort(fileArray, sizeOfFileArray);
  delete[] fileArray;
  return 0;
}
