#include "fill_array.h"
#include <cstddef>
#include <iostream>

void fillArray(int* arr, size_t nRow, size_t nColomn, std::ifstream& input)
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
