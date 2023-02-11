#include "fill_array.h"
#include <cstddef>
#include <iostream>

void fillDynArray(int** array_for_filling, size_t nRows, size_t nColomns, std::fstream& input)
{
  for (size_t i = 0; i < nRows; ++i)
  {
    for (size_t j = 0; j < nColomns; ++j)
    {
      input >> array_for_filling[i][j];
      if (!input)
      {
        std::cerr << "Error with input Dynamic array\n";
      }
    }
  }
}

void fillIntegratedArray(int* arr, size_t nRow, size_t nColomn, std::ifstream& input)
{
  for (size_t i = 0; i < nRow; ++i)
  {
    for (size_t j = 0; j < nColomn; ++j)
    {
      input >> arr[nRow * i + j];
      if (!input)
      {
        std::cerr << "Error with input Integrated array\n";
      }
    }
  }
}
