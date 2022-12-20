#include <iostream>
#include <fstream>
#include <cstring>
#include "countrows.h"
int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough parameters.\n";
    return 2;
  }
  if (argc > 4)
  {
    std::cerr << "Too much parameters.\n";
    return 2;
  }
  char *taskNumber = argv[1];
  std::string fileIn = argv[2];
  std::string fileOut = argv[3];
  std::fstream fileInput(fileIn);
  std::ofstream fileOutput(fileOut);
  if (!fileInput.is_open())
  {
    std::cerr << "Error while opening file " << fileIn << ".\n";
    return 2;
  }
  if (!fileOutput.is_open())
  {
    std::cerr << "Error while opening file " << fileOut << ".\n";
    return 2;
  }
  while (!fileInput.eof())
  {
    size_t rows = 0;
    fileInput >> rows;
    if (!fileInput)
    {
      std::cerr << "Error while reading rows.\n";
      return 2;
    }
    size_t columns = 0;
    fileInput >> columns;
    if (!fileInput)
    {
      std::cerr << "Error while reading columns.\n";
      return 2;
    }
    if (!strcmp(taskNumber, "1"))
    {
      size_t arraySize = rows * columns;
      int array[arraySize];
      if (arraySize <= 1000)
      {
        for (size_t i = 0; i < arraySize; i++)
        {
          fileInput >> array[i];
          if (!fileInput)
          {
            std::cerr << "Error while reading file " << fileIn << ".\n";
            return 2;
          }
        }
        size_t countDivEl = countDiverseElements(array, rows, columns);
        size_t countEqSum = countEqualSum(array, rows, columns);
        try
        {
          fileOutput << countDivEl << " " << countEqSum;
        }
        catch (...)
        {
          std::cerr << "Error while writing result.\n";
          return 2;
        }
      }
      else
      {
        std::cerr << "Maximum possible array size exceeded.\n";
        return 2;
      }
    }
    if (!strcmp(taskNumber, "2"))
    {
      size_t arraySize = rows * columns;
      int *array = new int[arraySize];
      for (size_t i = 0; i < arraySize; i++)
      {
        fileInput >> array[i];
        if (!fileInput)
        {
          std::cerr << "Error while reading file " << fileIn << ".\n";
          delete[] array;
          return 2;
        }
      }
      size_t countDivEl = countDiverseElements(array, rows, columns);
      size_t countEqSum = countEqualSum(array, rows, columns);
      int sM = smoothMatrix(array, rows);
      delete[] array;
      //std::cout << countDivEl << "\n";
      //std::cout << countEqSum << "\n";
      try
      {
        fileOutput << countDivEl << " " << countEqSum;
      }
      catch (...)
      {
        std::cerr << "Error while writing result.\n";
        return 2;
      }
    }
  }
}
