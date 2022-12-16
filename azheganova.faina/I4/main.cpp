#include<iostream>
#include <fstream>
#include <cstddef>
#include <cstring>
#include"countrowswithdifferentelements.h"
#include"findstringwithconsecutiveequalelements.h"

int main(int argc, char* argv[])
{
  if (argc > 4)
  {
    std::cout << "Too much parameters";
    return 1;
  }
  if (argc == 1)
  {
    std::cout << "No file name";
    return 1;
  }
  size_t m = 0;
  size_t n = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cout << "file open error";
    return 1;
  }
  input >> m;
  input >> n;
  size_t size = m * n;
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cout << "file open error";
    return 1;
  }
  if (!strcmp(argv[1], "1"))
  {
    int arr[1000];
    if (size > 1000)
    {
      std::cout << "too much elements";
      return 1;
    }
    for (size_t i = 0; i < size; ++i)
    {
      input >> arr[i];
      if (!input)
        {
          std::cout << "elements read error";
          return 1;
        }
    }
    std::ofstream output(argv[3]);
    size_t countdifferentelements = countRowsWithDifferentElements(arr, m, n);
    output << countdifferentelements << "\n";
    if (!output)
    {
      std::cout << "number write error";
      return 1;
    }
  }
  else if (!strcmp(argv[1], "2"))
  {
    if (size == 0)
    {
      output << "0";
      return 0;
    }
    int* arr = new int[size];
    for (size_t i = 0; i < n; i++)
    {
      for (size_t j = 0; j < m; j++)
      {
        input >> arr[i * n + j];
        if (!input)
        {
          std::cerr << "elements read error";
          delete[] arr;
          return 1;
        }
      }
    }
    size_t linenumber = findStringWithConsecutiveEqualElements(arr, m, n);
    output << linenumber << "\n";
    if (!output)
    {
      std::cout << "number write error";
      return 1;
    }
    delete[] arr;
  }
  return 0;
}
