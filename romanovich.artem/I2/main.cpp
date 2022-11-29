#include <iostream>
#include <fstream>
#include "time.h"
#include "oneDimensionalArrays.h"
#include "arrayDynamic.h"
int main(int argc, char **argv)
{
  size_t beginIndex = 0, endIndex = 1; // M and N
  //Const array
  const size_t arrayConstSize = 10;
  int arrayConst[arrayConstSize] = {1, -1, 3, 4, 5, 4, -1, -1, 2, 1};
  size_t countNrfmConst = countNegativeRightFromMax(arrayConst, arrayConstSize);
  size_t countRirConst = countRepetitiveInRange(arrayConst, arrayConstSize, beginIndex, endIndex);
  std::cout << countNrfmConst << std::endl;
  std::cout << countRirConst << std::endl;
  //Dynamic array
  size_t arrayDynamicSize = 0;
  std::cin >> arrayDynamicSize;
  if (!std::cin)
  {
    std::cerr << "Error while dynamic input." << std::endl;
    return 2;
  }
  ArrayDynamic arrayDynamic(arrayDynamicSize);
  std::srand(time(nullptr));
  for (size_t i = 0; i < arrayDynamicSize; i++)
  {
    arrayDynamic.size++;
    arrayDynamic.data[i] = std::rand() % 10 - 5;
  }
  size_t countNrfmDynamic = countNegativeRightFromMax(arrayDynamic.data, arrayDynamicSize);
  size_t countRirDynamic = countRepetitiveInRange(arrayDynamic.data, arrayDynamicSize, beginIndex, endIndex);
  std::cout << countNrfmDynamic << std::endl;
  std::cout << countRirDynamic << std::endl;
  //File array
  if (argc == 1)
  {
    std::cout << "No file provided.";
    return 2;
  }
  if (argc > 2)
  {
    std::cout << "Too much parameters." << std::endl;
    return 2;
  }
  size_t arrayFileSize = 0;
  std::string fileName = argv[1];
  std::fstream fileInput(fileName);
  if (!fileInput.is_open())
  {
    std::cerr << "Error while opening file " << argv[1] << std::endl;
    return 2;
  }
  fileInput >> arrayFileSize;
  if (!fileInput)
  {
    std::cerr << "Error while reading file " << argv[1] << std::endl;
    return 2;
  }
  int *arrayFile = new int[arrayFileSize];
  while (!fileInput.eof())
  {
    for (size_t i = 0; i < arrayFileSize; i++)
    {
      fileInput >> arrayFile[i];
      if (!fileInput)
      {
        std::cerr << "Error while reading file " << argv[1] << std::endl;
        delete[] arrayFile;
        return 2;
      }
    }
  }
  size_t countNrfmFile = countNegativeRightFromMax(arrayFile, arrayFileSize);
  size_t countRirFile = countRepetitiveInRange(arrayFile, arrayFileSize, beginIndex, endIndex);
  std::cout << countNrfmFile << std::endl;
  std::cout << countRirFile << std::endl;
}
