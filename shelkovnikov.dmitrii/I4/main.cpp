#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include "count_columns_with_ascending_elements.h"
#include "count_lines_with_unique_elements.h"
int main(int argc, char *argv[])
{
  if (argc > 4)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  if (argc != 4)
  {
    std::cout << "Pls check parameters";
    return 1;
  }
  size_t n = 0;
  size_t m = 0;
  std::ifstream in(argv[2]);
  in >> n >> m;
  if (argv[1] == 1)
  {
    int arr[n * m];
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        in >> arr[n * i + j];
      }
    }
    std::cout << count_columns_with_ascending_elements(arr, n, m) << "\n";
    std::cout << count_lines_with_unique_elements(arr, n, m) << "\n";
  }
  else
  {
    try
    {
      int *arr = new int[n * m];
      for (size_t i = 0; i < n; i++)
      {
        for (int j = 0; j < m; j++)
        {
          in >> arr[i * n + j];
        }
      }
      std::cout << count_columns_with_ascending_elements(arr, n, m) << "\n";
      std::cout << count_lines_with_unique_elements(arr, n, m) << "\n";
    }
  }
  return 0;
}
