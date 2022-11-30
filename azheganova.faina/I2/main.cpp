#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include "arrays.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cout << "Not correct amolunt of CML args\n";
  }
  int staticarray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  try
  {
    shiftarrayleft(staticarray, 10);
    for (size_t i = 0; i < 10; i++)
    {
      std::cout << staticarray[i] << " ";
    }
    transferofvariables(staticarray, 10);
    for (size_t newi = 0; newi < 10; newi++)
    {
      std::cout << staticarray[newi] << ' ';
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
  if (!std::cin)
  {
    std::cout << "Not a number";
    return 2;
  }
  int* dynamicarray = new int[n];
  srand(time(0));
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
    for (size_t newi = 0; newi < n; newi++)
    {
      std::cout << dynamicarray[newi] << ' ';
    }
  }
  catch(const std::exception& e)
  {
    std::cout << e.what();
    delete[] dynamicarray;
    return 2;
  }
  delete[] dynamicarray;
  size_t size = 0;
  std::string name = argv[1];
  std::fstream file(name);
  if (!file.is_open())
  {
    std::cout << "file open error";
    return 2;
  }
  file >> size;
  if (!file)
  {
    std::cout << "file reading error";
    return 2;
  }
  int* arrInput = new int[size];
  for (size_t i=0; i < size; i++)
  {
    file >> arrInput[i];
    if (!file)
    {
      std::cout << "file reading error";
      return 2;
    }
  }
  if (size = 0)
  {
    return 0;
  }
  else
  {
    try
    {
      shiftarrayleft(arrInput, size);
      for (size_t i = 0; i < size; i++)
      {
        std::cout << arrInput[i] << " ";
      }
      transferofvariables(arrInput, size);
      for (size_t newi = 0; newi < size; newi++)
      {
        std::cout << arrInput[newi] << ' ';
      }
    }
    catch (const std::overflow_error &e)
    {
      std::cout << e.what();
      delete[] arrInput;
      return 2;
    }
  }
  delete[] arrInput;
  return 0;
}
