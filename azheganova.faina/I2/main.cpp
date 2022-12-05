#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include "arrays.h"

int main(int argc, char *argv[])
{
  if (argc > 2)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  if (argc == 1)
  {
    std::cout << "No file name";
    return 1;
  }
  const size_t staticarray_size = 10;
  int staticarray[staticarray_size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int shiftamount = 0;
  std::cin >> shiftamount;
  try
  {
    ShiftArrayLeft(staticarray, staticarray_size, shiftamount);
    for (size_t i = 0; i < staticarray_size; i++)
    {
      std::cout << staticarray[i] << " ";
    }
    TransferVariables(staticarray, staticarray_size);
    for (size_t i = 0; i < staticarray_size; i++)
    {
      std::cout << staticarray[i] << " ";
    }
  }
  catch (const std::overflow_error &e)
  {
    std::cout << e.what();
    return 2;
  }
  size_t n = 0;
  std::cout << "Dynamic array size:\n";
  std::cin >> n;
  int* dynamicarray = new int[n];
  std::srand(time(0));
  for (size_t i = 0; i < n; i++)
  {
    dynamicarray[i] = std::rand();
  }
  int shiftamountdyn = 0;
  std::cin >> shiftamountdyn;
  ShiftArrayLeft(dynamicarray, n, shiftamountdyn);
  for (size_t i = 0; i < n; i++)
  {
    std::cout << dynamicarray[i] << " ";
  }
  TransferVariables(dynamicarray, n);
  for (size_t i = 0; i < n; i++)
  {
    std::cout << dynamicarray[i] << " ";
  }
  delete[] dynamicarray;
  std::ifstream file(argv[1]);
  if (!file.is_open())
  {
    std::cout << "file open error";
    return 1;
  }
  while (!file.eof())
  {
    size_t size = 0;
    file >> size;
    if (!file)
    {
      std::cout << "file reading error";
      return 1;
    }
    int* arrInput = new int[size];
    for (size_t i = 0; i < size; i++)
    {
      file >> arrInput[i];
      if (!file)
      {
        std::cout << "file reading error";
        delete[] arrInput;
        return 1;
      }
    }
    int shiftamountinput = 0;
    std::cin >> shiftamountinput;
    ShiftArrayLeft(arrInput, size, shiftamountinput);
    for (size_t i = 0; i < size; i++)
    {
      std::cout << arrInput[i] << " ";
    }
    TransferVariables(arrInput, size);
    for (size_t i = 0; i < size; i++)
    {
      std::cout << arrInput[i] << " ";
    }
    delete[] arrInput;
  }
  return 0;
}
