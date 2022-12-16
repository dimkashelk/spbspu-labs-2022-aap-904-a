#include<iostream>
#include <fstream>
#include <cstddef>
#include"countrowswithdifferentelements.h"

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
  if (!std::strcmp(argv[1], "1"))
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
}