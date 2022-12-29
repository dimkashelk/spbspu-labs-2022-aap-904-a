#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include "sumindexelements.h"
#include "largestdengthdecreasing.h"
int main (int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Error" << "\n";
    return 1;
  }
  int arr_1[10] = {10, 8, 6, 4, 2, 8, 5, 7, 3, 1};
  try
  {
    std::cout << sum_index_elements(arr_1, 10) << std::endl;
    std::cout << largest_dength_decreasing (arr_1, 10) << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  size_t n = 0;
  std::cin >> n;
  int * arr_2 = new int[n];
  const unsigned int srand_arg = 1;
  std::srand(srand_arg);
  for (int i = 0; i < n; i++)
  {
    arr_2[1] = std::rand();
  }
  try
  {
    std::cout << sum_index_elements(arr_2, n) << std::endl;
    std::cout << largest_dength_decreasing(arr_2, n) << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] arr_2;
    return 2;
  }
  delete[] arr_2;
  std::ifstream in(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file";
    return 1;
  }
  while (!in.eof())
  {
    size_t size = 0;
    in >> size;
    if (!in)
    {
      std::cout << "Error... =(";
      return 1;
    }
    int *arr_3 = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      in >> arr_3[i];
      if (!in)
      {
        std::cout << "Error... =(";
        delete[] arr_3;
        return 1;
      }
    }
    try
    {
      std::cout << sum_index_elements(arr_3, size) << "\n";
      std::cout << largest_dength_decreasing(arr_3, size) << "\n";
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what();
      delete[] arr_3;
      return 2;
    }
    delete[] arr_3;
  }
  return 0;
}

