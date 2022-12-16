#include<iostream>
#include <fstream>
#include <cstddef>
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
  std::ifstream inputfile(argv[2]);
  if (!inputfile.is_open())
  {
    std::cout << "file open error";
    return 1;
  }
  inputfile >> m;
  inputfile >> n;
  size_t size = m * n;
  std::ofstream outputfile(argv[3]);
  if (!outputfile.is_open())
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
      inputfile >> arr[i];
      if (!inputfile)
        {
          std::cerr << "elements read error";
          return 1;
        }
    }
    size_t countdifferentelements = countRowsWithDifferentElements(arr, m, n);
    outputfile << countdifferentelements << "\n";
    if (!outputfile)
    {
      std::cout << "number write error";
      return 1;
    }
  }
  else
  {
    if (size == 0)
    {
      outputfile << "0";
      return 0;
    }
    int* arr = new int[size];
    for (size_t i = 0; i < size; ++i)
    {
      inputfile >> arr[i];
      if (!inputfile)
      {
        std::cerr << "elements read error";
        delete[] arr;
        return 1;
      }
    }
    size_t squarematrixsize = std::min(m, n);
    int* squarematrix = nullptr;
    if (m == n)
    {
      squarematrix = arr;
      arr = nullptr;
    }
    else
    {
      squarematrix = new int[squarematrixsize * squarematrixsize];
    }
    if (n < m)
    {
      for (size_t i = 0; i < (squarematrixsize * squarematrixsize); ++i)
      {
        squarematrix[i] = arr[i];
      }
    }
    else if (n > m)
    {
      for (size_t i = 0; i < squarematrixsize; ++i)
      {
        for (size_t j = 0; j < squarematrixsize; ++j)
        {
          squarematrix[(i * squarematrixsize) + j] = arr[(i * n) + j];
        }
      }
    }
    size_t linenumber = findStringWithConsecutiveEqualElements(arr, m, n);
    outputfile << linenumber << "\n";
    if (!outputfile)
    {
      std::cout << "number write error";
      return 1;
    }
  }
  return 0;
}
