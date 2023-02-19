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
  }
  size_t sizeOfFileArray = 0;
  in >> sizeOfFileArray;
  if (sizeOfFileArray == 0)
  {
    throw std::logic_error("Error: incorrect size of file array");
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
  try
  {
    std::cout << "Count of triplets: " << isTriplet(fileArray, sizeOfFileArray) << " in the file array" << std::endl;
    sort(fileArray, sizeOfFileArray);
  }
  catch (const std::logic_error &e)
  {
    return 1;
  }
  delete[] fileArray;
  return 0;
}
