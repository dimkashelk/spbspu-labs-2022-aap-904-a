#include <iostream>
#include <fstream>
#include "time.h"
#include "oneDimensionalArrays.h"
#include "arrayDynamic.h"
int main(int argc, char **argv)
{
  //Const array
  const size_t arrayConstSize = 10;
  int arrayConst[arrayConstSize] = {1, -1, 3, 4, 5, 4, -1, -1, 2, 1};
  //Dynamic array
  size_t arrayDynamicSize = 0;
  std::cout << "Print dynamic array size:" << std::endl;
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
  //Counting answer
  size_t beginIndex = -1, endIndex = -1;
  std::cout << "Print the range beginIndex:" << std::endl;
  std::cin >> beginIndex;
  std::cout << "Print the range endIndex:" << std::endl;
  std::cin >> endIndex;
  size_t countNrfmConst = countNegativeRightFromMax(arrayConst, arrayConstSize);
  size_t countNrfmDynamic = countNegativeRightFromMax(arrayDynamic.data, arrayDynamicSize);
  size_t countNrfmFile = countNegativeRightFromMax(arrayFile, arrayFileSize);
  const char *countRirConst = countRepetitiveInRange(arrayConst, arrayConstSize, beginIndex, endIndex);
  const char *countRirDynamic = countRepetitiveInRange(arrayDynamic.data, arrayDynamicSize, beginIndex, endIndex);
  const char *countRirFile = countRepetitiveInRange(arrayFile, arrayFileSize, beginIndex, endIndex);
  //Print
  std::cout << "Number of negative elements right from max element:" << std::endl;
  std::cout << "Const: " << countNrfmConst << std::endl;
  std::cout << "Dynamic: " << countNrfmDynamic << std::endl;
  std::cout << "File: " << countNrfmFile << std::endl;
  std::cout << "Repetitive elements exists in range from 0 to 0:" << std::endl;
  std::cout << "Const: " << countRirConst << std::endl;
  std::cout << "Dynamic: " << countRirDynamic << std::endl;
  std::cout << "File: " << countRirFile << std::endl;
}
