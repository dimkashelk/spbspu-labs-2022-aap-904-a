#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include "arrays.h"

int main(int argc, char ** argv)
{
  if (argc != 2)
  {
    std::cout << "Not correct amolunt of CML args\n";
  }
  const size_t staticarray_size = 10;
  int staticarray[staticarray_size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  try
  {
    shiftarrayleft(staticarray, staticarray_size);
    for (size_t i = 0; i < staticarray_size; i++)
    {
      std::cout << staticarray[i] << " ";
    }
    transferofvariables(staticarray, staticarray_size);
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
  try
  {
    shiftarrayleft(dynamicarray, n);
    for (size_t i = 0; i < n; i++)
    {
      std::cout << dynamicarray[i] << " ";
    }
    transferofvariables(dynamicarray, n);
    for (size_t i = 0; i < n; i++)
    {
      std::cout << dynamicarray[i] << " ";
    }
  }
  catch(const std::exception &e)
  {
    std::cout << e.what();
    delete[] dynamicarray;
    return 2;
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
    for (size_t i=0; i < size; i++)
    {
      file >> arrInput[i];
      if (!file)
      {
        std::cout << "file reading error";
        delete[] arrInput;
        return 1;
      }
    }
    try
    {
      shiftarrayleft(arrInput, size);
      for (size_t i = 0; i < size; i++)
      {
        std::cout << arrInput[i] << " ";
      }
      transferofvariables(arrInput, size);
      for (size_t i = 0; i < size; i++)
      {
        std::cout << arrInput[i] << " ";
      }
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what();
      delete[] arrInput;
      return 2;
    }
    delete[] arrInput;
  }
  return 0;
}
