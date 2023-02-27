#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>
#include "input_array_size.h"
#include "number_of_rows_with_same_elements.h"
#include "max_sum_diag.h"


int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "condition not met\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Error while reading file...\n";
    return 1;
  }
  size_t n = 0;
  size_t m = 0;
  input >> n;
  input >> m;
  if (!input)
  {
    std::cerr << "Problems with input rows or colomns\n";
    return 1;
  }
  if (n * m > 1000)
  {
    std::cout << "condition not met";
    return 1;
  }
  std::ofstream outputfile(argv[3]);
  if (!outputfile)
  {
    std::cerr << "Problems with file output...\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    if (!inputArraySize(n, m))
    {
      std::cerr << "Error with input...";
      return 1;
    }
    int arr[1000];
    try
    {
      for (size_t i = 0; i < n; ++i)
      {
        for (size_t j = 0; j < m; ++j)
        {
          input >> arr[n * i + j];
          if (!input)
          {
            std::cout << "Error with input integrated array\n";
            return 1;
          }
        }
      }
      outputfile << counterOfRowsWithSameElements(arr, n, m) << "\n";
      if (!outputfile)
      {
        std::cout << "Error with writting in output file\n";
        return 1;
      }
    }
    catch (std::exception &e)
    {
      std::cerr << e.what();
      return 2;
    }
  }
  if (!std::strcmp(argv[1], "2"))
  {
    if (!inputArraySize(n, m))
    {
      std::cerr << "Error with input...";
      return 1;
    }
    int* dyn_array = new int[n * m];
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        input >> dyn_array[n * i + j];
        if (!input)
        {
          std::cout << "Error with input dynamic array\n";
          delete[] dyn_array;
          return 1;
        }
      }
    }
    try
    {
      outputfile << maxSumDiag(dyn_array, n, m) << "\n";
      if (!outputfile)
      {
        std::cerr << "Error with writting in output file\n";
        delete[] dyn_array;
        return 1;
      }
    }
    catch (std::exception& e)
    {
      std::cerr << e.what();
      return 2;
    }
      delete[] dyn_array;
  }
  return 0;
}
