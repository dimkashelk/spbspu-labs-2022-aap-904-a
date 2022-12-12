#include <iostream>
#include <fstream>
#include "shiftarray.h"
#include "evenfirst.h"
#include "outputarray.h"

int main(int argc, char* argv[])
{
  if (argc != 2)
  {
    std::cout << "error input";
    return 1;
  }
  constexpr size_t size1 = 5;
  int arr1[5] = {4, 5, 6, 7,8};
  constexpr unsigned shift1 = 1;
  try
  {
    outputArray(std::cout, arr1, size1) << '\n';
    shiftArray(arr1, size1, shift1);
    outputArray(std::cout, arr1, size1) << '\n';
    evenFirst(arr1, size1);
    outputArray(std::cout, arr1, size1) << '\n';
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 1;
  }
  size_t size2 = 0;
  constexpr unsigned shift2 = 0;
  std::cin >> size2;
  int* arr2 = new int[size2];
  std::srand(time(nullptr));
  for (size_t i = 0; i < size2; i++)
  {
    arr2[i] = std::rand();
  }
  try
  {
    outputArray(std::cout, arr2, size2) << '\n';
    shiftArray(arr2, size2, shift2);
    outputArray(std::cout, arr2, size2) << '\n';
    evenFirst(arr2, size2);
    outputArray(std::cout, arr2, size2) << '\n';
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    delete[] arr2;
    return 1;
  }
  delete[] arr2;
  std::ifstream file(argv[1]);
  if (!file.is_open())
  {
    std::cout << "error while opening" << "\n";
    return 1;
  }
  int *arr3;
  size_t size3 = 0;
  constexpr unsigned shift3 = 1;
  file >> size3;
  if (!file)
  {
    std::cout << "error wile reading" << "\n";
    return 1;
  }
  arr3 = new int[size3];
  for (int i = 0; i < size3; i++)
  {
    file >> arr3[i];
    if (!file)
    {
      std::cout << "error while reading" << "\n";
      delete[] arr3;
      return 1;
    }
  }
  try
  {
    outputArray(std::cout, arr3, size3) << '\n';
    shiftArray(arr3, size3, shift3);
    outputArray(std::cout, arr3, size3) << '\n';
    evenFirst(arr3, size3);
    outputArray(std::cout, arr3, size3) << '\n';
  }
  catch (const std::invalid_argument &e)
  {
    std::cout << "error";
    std::cout << e.what();
    delete[] arr3;
    return 1;
  }
  delete[] arr3;
  return 0;
}
