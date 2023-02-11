#include "readthearray.hpp"
#include "istriplet.hpp"
#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
int readTheArray(std::string fileName)
{
  std::ifstream in(fileName);
  if (!in.eof())
  {
   std::cout << "Error: file is empty" << std::endl;
   return 1;
  }
  size_t sizeOfFileArray = 0;
  in >> sizeOfFileArray;
  if (!in)
  {
   std::cout << "Error: input size is invalid or empty" << std::endl;
   return 1;
  }
  if (sizeOfFileArray == 0)
  {
   std::cout << "Error: size of array = 0" << std::endl;
   return 1;
  }
  int * fileArray = new int[sizeOfFileArray];
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      std::cout << "Error: input is empty" << std::endl;
      in.close();
      delete[] fileArray;
      return 1;
    }
  }
  std::cout << "Count of triplets: " << isTriplet(fileArray, sizeOfFileArray) << " in the file array" << std::endl;
  sort(fileArray, sizeOfFileArray);
  delete[] fileArray;
  return 0;
}
