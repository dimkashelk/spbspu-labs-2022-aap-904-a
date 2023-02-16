#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "RowsWithoutSimVal.h"
#include "ColsWithZero.h"
int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    std::cout << "Invalid argumets" << "\n";
    return 1;
  }
  std::ifstream inputFile(argv[2]);
  if (!inputFile.is_open())
  {
    std::cout << "Input error" << "\n";
    return 1;
  }
  size_t r = 0;
  size_t c = 0;
  inputFile >> r >> c;
  if (!inputFile)
  {
    std::cout << "Input error" << "\n";
    inputFile.close();
    return 1;
  }
  std::ofstream outputFile(argv[3]);
  if (!outputFile.is_open())
  {
    std::cout << "Output file not open" << "\n";
    inputFile.close();
    outputFile.close();
    return 1;
  }
  if (std::strcmp(argv[1], "1") == 0)
  {
    int arr[1000];
    if (r * c > 1000)
    {
      std::cout << "Array > 1000" << "\n";
      inputFile.close();
      outputFile.close();
      return 1;
    }
    for (size_t i = 0; i < r * c; i++)
    {
      inputFile >> arr[i];
      if (!inputFile)
      {
        std::cout << "Error while input" << "\n";
        inputFile.close();
        outputFile.close();
        return 1;
      }
    }
    outputFile << countColsWithZero(arr, r, c) << "\n";
  }
  else if (std::strcmp(argv[1], "2") == 0)
  {
    int *dynarr = nullptr;
    try
    {
      dynarr = new int[r * c];
    }
    catch (const std::bad_alloc &e)
    {
      delete [] dynarr;
      inputFile.close();
      outputFile.close();
      return 1;
    }
    for (size_t i = 0; i < r * c; i++)
    {
      inputFile >> dynarr[i];
      if (!inputFile)
      {
        std::cout << "Error while input" << "\n";
        inputFile.close();
        outputFile.close();
        delete [] dynarr;
        return 1;
      }
    }
     outputFile << countRows(dynarr, r, c) << "\n" ;
     delete [] dynarr;
  }
  else
  {
    std::cout << "Error" << "\n";
    inputFile.close();
    outputFile.close();
    return 1;
  }
  inputFile.close();
  outputFile.close();
  return 0;
}
