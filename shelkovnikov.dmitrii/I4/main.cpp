#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include "count_lines_with_unique_elements.h"
#include "minimum_sums_of_diagonals.h"
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
  if (!in)
  {
    std::cout << "Error";
    return 1;
  }
  if (*argv[1] == '1')
  {
    int arr[n * m];
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        in >> arr[n * i + j];
        if (!in)
        {
          std::cout << "Error";
          return 1;
        }
      }
    }
    std::ofstream out(argv[3]);
    out << count_lines_with_unique_elements(arr, n, m) << "\n";
    out << minimum_sums_of_diagonals(arr, n, m) << "\n";
  }
  else if (*argv[1] == '2')
  {
    try
    {
      int *arr = new int[n * m];
      for (size_t i = 0; i < n; i++)
      {
        for (size_t j = 0; j < m; j++)
        {
          in >> arr[i * n + j];
          if (!in)
          {
            std::cout << "Error";
            return 1;
          }
        }
      }
      std::ofstream out(argv[3]);
      out << count_lines_with_unique_elements(arr, n, m) << "\n";
      out << minimum_sums_of_diagonals(arr, n, m) << "\n";
      delete[] arr;
    }
    catch (const std::bad_alloc &e)
    {
      std::cout << "Error";
      return 2;
    }
  }
  else
  {
    std::cout << "No such parameter";
    return 1;
  }
  return 0;
}
