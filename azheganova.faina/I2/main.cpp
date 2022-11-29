#include <iostream>
#include <stdexcept>
#include <fstream>
#include <cstddef>
#include "arrays.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Not correct amolunt of CML args\n";
  }
  int staticarray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
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
  delete[] dynamicarray;
  std::ifstream file(argv[1]);
  if (!file)
  {
    std::cerr << argv[1] << "file open error";
    return 2;
  }
  size_t size = 0;
  file >> size;
  int* arrInput = new int[size];
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
  delete[] arrInput;
  return 0;
}
