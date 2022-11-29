#include <iostream>
#include <exception>
#include<fstream>
#include<string>
#include "arrays.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    std::cerr << "Not correct amolunt of CML args\n";
    return 1;
  }
  int staticarray[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  try
  {
    std::cout << shiftarrayleft(staticarray, 10) << '\n';
    std::cout << transferofvariables(staticarray, 10) << '\n';
  }
  catch (const std::overflow_error& e)
  {
    std::cout << e.what() << "\n";
    return 2;
  }
  size_t n = 0;
  std::cout << "Dynamic array size:\n";
  std::cin >> n;
  if (!std::cin)
  {
    std::cout << "Not a number";
    return 1;
  }
  if (n>0)
  {
    int* dynamicarray = new int[n];
    srand(time(0));
    for (size_t i = 0; i < n; i++)
    {
      dynamicarray[i] = std::rand();
    }
    try
    {
      for (size_t i = 0; i < n; i++)
      {
        std::cout << dynamicarray[i] << " ";
      }
      std::cout << '\n';
      std::cout << shiftarrayleft(dynamicarray, n) << '\n';
      std::cout << transferofvariables(dynamicarray, n) << '\n';
    }
    catch (const std::overflow_error& e)
    {
      std::cout << e.what() << "\n";
      delete[] dynamicarray;
      return 2;
    }
    delete[] dynamicarray;
  }
  else
  {
    std::cerr << "incorrect value";
  }
  std::ifstream file(argv[1]);
  if (!file)
  {
    std::cerr << argv[1] << "file open error";
    return 1;
  }
  size_t size = 0;
  file >> size;
  int* arrInput = new int[size];
  try
  {
    std::cout << shiftarrayleft(arrInput, size) << "\n";
    std::cout << transferofvariables(arrInput, size) << "\n";
  }
  catch (const std::overflow_error& e)
  {
    std::cout << e.what() << "\n";
    delete[] arrInput;
    return 2;
  }
  delete[] arrInput;
  return 0;
}
