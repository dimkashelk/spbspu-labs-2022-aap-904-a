#include <stdexcept>
#include <iostream>
#include <cstddef>
#include <fstream>
#include "sumindexelements.h"
#include "lengthlongerdecreasing.h"
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
    std::cout << sum_index_elements(arr_1, 10) << "\n";
    std::cout << length_longer_decreasing(arr_1, 10) << "\n";
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  try
  {
    size_t n = 0;
    std::cin >> n;
    int * arr_2 = new int[n];
    std::srand(time(nullptr));
    for (size_t i = 0; i < n; i++)
    {
      arr_2[i] = (std::rand() % 10) + 1;
    }
    try
    {
      std::cout << sum_index_elements(arr_2, n) << "\n";
      std::cout << length_longer_decreasing(arr_2, n) << "\n";
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what() << "\n";
      delete[] arr_2;
      return 2;
    }
     delete[] arr_2;
  }
  catch (const std::bad_array_new_length &e)
  {
    std::cout << e.what() << "\n";
    return 2;
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what() << "\n";
    return 2;
  }
  std::ifstream in(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file" << "\n";
    return 1;
  }

  if (in.eof() == std::ifstream::traits_type::eof())
  {
    std::cout << "Error." << "\n";
    return 1;
  }
  size_t size = 0;
  in >> size;
  if (size == 0)
  {
    std::cout << "Error size = 0" << "\n";
    return 0;
  }
  if(in.eof() == std::ifstream::traits_type::eof())
  {
    std::cout << "Error.." << "\n";
    return 1;
  }
  int *arr_3 = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    in >> arr_3[i];
  }
  try
  {
    std::cout << sum_index_elements(arr_3, size) << "\n";
    std::cout << length_longer_decreasing(arr_3, size) << "\n";
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what() << "\n";
    delete[] arr_3;
    return 2;
  }
  delete[] arr_3;
  return 0;
}
