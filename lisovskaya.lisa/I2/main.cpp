#include <cstddef>
#include <iostream>
#include <fstream>
#include "counter_before_min.h"
#include "findArithmeticMean.h"
#include "generateRand.h"
#include "readArray.h"
int main(int argc, char *argv[])
{
  if (argc == 1)
  {
    std::cout << "file name is missing :(";
    return 1;
  }
  if (argc > 2)
  {
    std::cout << "far too much parametrs -_-";
    return 1;
  }
  int arr1[] = {2, 5, 3, 4, 6, 7, 1};
  std::cout << counter_before_min(arr1, 7) << std::endl;
  std::cout << findArithmeticMean(arr1, 7) << std::endl;
  size_t n = 0;
  std::cin >> n;
  int *array2 = generateRand(n);
  try
  {
    std::cout << counter_before_min(array2, n) << std::endl;
    std::cout << findArithmeticMean(array2, n) << std::endl;
  }
  catch (const std::runtime_error &e)
  {
    std::cout << 0 << "\n" << 0;
  }
  delete[] array2;
  std::ifstream in(argv[1]);
  size_t size = 0;
  in >> size;
  if (!in)
  {
    std::cout << "empty file :(";
    return 1;
  }
  int *array3 = readArray(argv[1]);
  try
  {
    std::cout << counter_before_min(array3, size) << "\n";
    std::cout << findArithmeticMean(array3, size) << "\n";
  }
  catch (const std::runtime_error &e)
  {
    std::cout << e.what();
  }
  delete[] array3;
  return 0;
}
