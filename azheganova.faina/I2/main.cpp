#include <iostream>
#include <exception>
#include<fstream>
#include<string>
#include "transferofvariables.h"
#include "shiftarrayleft.h"

const std::string INPUT_FILE = "input.txt";
int main()
{
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
  
  int* dynamicarray = new int[n];
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
  std::ifstream file(INPUT_FILE);
  if (!file.is_open())
  {
    std::cout << "file open error";
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
