#include <iostream>
#include <cstddef>
#include <fstream>
#include <cstring>
#include "input_array_size.h"
#include "fill_array.h"
#include "number_of_rows_with_same_elements.h"
#include "max_sum_diag.h"


int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "condition not met\n";
    return -1;
  }
  std::ifstream input(argv[2]);
  if (!input)
  {
    std::cerr << "Error whil reading file...\n";
    return -1;
  }
  size_t n = 0;
  size_t m = 0;
  input >> n;
  input >> m;
  if (!input)
  {
    std::cerr << "Problems with input rows or colomns\n";
    return -1;
  }
  if (n * m > 1000)
  {
    std::cerr << "condition not met";
    return -1;
  }
  std::ofstream outputfile(argv[3]);
  if (!outputfile)
  {
    std::cerr << "Problems with file output...\n";
    return -1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int arr[1000];
    try
    {
      inputArraySize(n, m);
      fillIntegratedArray(arr, n, m, input);
      outputfile << counterOfRowsWithSameElements(arr, n, m) << "\n";
      if (!outputfile)
      {
        std::cerr << "Error with writting in output file\n";
        return -1;
      }
    }
    catch (std::exception &e)
    {
      std::cerr << e.what();
      return -1;
    }
  }
  if (!std::strcmp(argv[1], "2"))
  {
    int arr[1000];
    try
    {
      inputArraySize(n, m);
      int **arr = new int*[n];
      for (size_t i = 0; i < n; ++i)
      {
        arr[i] = new int[m];
      }
      fillDynArray(arr, n, m, input);
      size_t size_dyn_arr;
      outputfile << maxSumDiag(arr, size_dyn_arr);
      for (size_t i = 0; i < n; ++i)
      {
        delete[] arr[i];
      }
      delete[] arr;
      if (!outputfile)
      {
        std::cerr << "Error with writting in output file\n";
        return -1;
      }
    }
    catch (std::exception &e)
    {
      std::cerr << e.what();
      return -1;
    }
  }
  return 0;
}
