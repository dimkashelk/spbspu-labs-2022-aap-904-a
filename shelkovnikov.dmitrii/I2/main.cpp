#include "countorderedelements.h"
#include "countmaximumelements.h"
#include <stdexcept>
#include <iostream>
#include <fstream>
int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  if (argc == 1)
  {
    std::cout << "No file name....";
    return 1;
  }
  int arr1[] = {1, 2, 3, 4, 5, 6, 7};
  try
  {
    std::cout << count_maximum_elements(arr1, 7) << std::endl;
    std::cout << count_ordered_elements(arr1, 7) << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  int n = 0;
  std::cin >> n;
  int *arr2 = new int[n];
  srand(time(NULL));
  for (int i = 0; i < n; i++)
  {
    arr2[i] = rand();
  }
  try
  {
    std::cout << count_maximum_elements(arr2, n) << std::endl;
    std::cout << count_ordered_elements(arr2, n) << std::endl;
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] arr2;
    return 2;
  }
  delete[] arr2;
  std::ifstream in(argv[1]);
  if (!in.is_open())
  {
    std::cout << "Error while opening file";
    return 1;
  }
  while (!in.eof())
  {
    int size = 0;
    in >> size;
    if (!in)
    {
      std::cout << "Error... =(";
      return 1;
    }
    int *arr3 = new int[size];
    for (int i = 0; i < size; i++)
    {
      in >> arr3[i];
      if (!in)
      {
        std::cout << "Error... =(";
        delete[] arr3;
        return 1;
      }
    }
    try
    {
      std::cout << count_maximum_elements(arr3, size) << std::endl;
      std::cout << count_ordered_elements(arr3, size) << std::endl;
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what();
      delete[] arr3;
      return 2;
    }
    delete[] arr3;
  }
  return 0;
}
