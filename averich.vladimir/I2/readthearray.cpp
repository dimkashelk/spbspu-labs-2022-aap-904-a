#include "readthearray.hpp"
#include "istriplet.hpp"
#include "sort.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
int readTheArray(std::string fileName)
{
  std::ifstream in(fileName);
  size_t sizeOfFileArray = 0;
  in >> sizeOfFileArray;
  if (sizeOfFileArray == 0)
  {
    return 0;
  }
  int *fileArray = new int[sizeOfFileArray];
  for (size_t i = 0; i < sizeOfFileArray; i++)
  {
    in >> fileArray[i];
    if (!in)
    {
      in.close();
      delete[] fileArray;
      return 0;
    }
  }
  std::cout << "Count of triplets: " << isTriplet(fileArray, sizeOfFileArray) << " in the file array" << std::endl;
  sort(fileArray, sizeOfFileArray);
  delete[] fileArray;
  return 0;
}
