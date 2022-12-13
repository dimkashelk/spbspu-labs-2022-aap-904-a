#include <stddef>
#include <iostream>
#include <cstdef>
#include <fstream>
#include "counter_before_min.h"
#include "arithmetic_mean.h"
int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cout << "file name is missing :(";
    return 1;
  }
  if (argc > 2)
  {
    std::cout << "far too much parametrs -_-"
    return 1;
  }
  int arr1[] = {2, 5, 3, 4, 6, 7, 1};
  std::cout << counter_before_min(arr1, 7) << std::endl;
  std::cout << arith_mean(arr1, 7) << std::endl;
  size_t n = 0;
  std::cin >> n;
  int *array2 = new int[n];
  std::srand(time(nullptr));
  for (size_t i = 0; i < n; i++)
  {
    array2[i] = std::rand();
  }
  try
  {
    std::cout << count_before_min(array2, n) << std::endl;
    std::cout << arith_mean(array2, n) << std::endl;
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what();
    delete[] array2;
    return 2;
  }
  delete[] array2;
  std::ifstream in(argv[1]);
  size_t size = 0;
  in >> size;
  int *array3 = new int[size];
  for (size_t i = 0; i < size; i++)
  {
    in >> array3[i];
  }
  try
  {
    std::cout << count_before_min(array3, size) << "\n";
    std::cout << arith_mean(array3, size) << "\n";
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what();
    delete[] array3;
    return 2;
  }
  delete[] array3;
  return 0;
}
