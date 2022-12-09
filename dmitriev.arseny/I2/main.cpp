#include <iostream>
#include <fstream>
#include "shiftArray.h"
#include "countOrderedTriples.h"


int main(int argc, char* arr[])
{
  if (argc != 2)
  {
    std::cout << "Problems with input";
    return 1;
  }

  int arr1[5] = { 4, 5, 1, 2, 6 };
  const size_t size1 = 5;
  size_t shift1 = 2;
  try
  {
    shiftArray(arr1, size1, shift1);
    countOrderedTriples(arr1, size1);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Error: ";
    std::cout << e.what();
    return 1;
  }

  size_t size2 = 0;
  size_t shift2 = 0;
  std::cin >> size2;
  if (size2 < 0)
  {
    std::cout << "No arr is possible" << "\n";
  }
  int* arr2 = new int[size2];
  std::srand(time(nullptr));
  for (int i = 0; i < size2; i++)
  {
    arr2[i] = rand();
  }
  try
  {
    shiftArray(arr2, size2, shift2);
    countOrderedTriples(arr2, size2);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Error: ";
    std::cout << e.what();
    delete[] arr2;
    return 1;
  }
  delete[] arr2;
 
  std::ifstream file;
  std::string name = arr[1];
  file.open(name);
  if (!file.is_open())
  {
    std::cout << "Error while opening file" << "\n";
    return 1;
  }
  int* arr3;
  size_t size3 = 0;
  size_t shift3 = 1;
  file >> size3;
  if (!file)
  {
    std::cout << "Error while opening file" << "\n";
    return 1;
  }
  if (shift3 < 0)
  {
    std::cout << "Error while reading file";
    return 1;
  }
  arr3 = new int[size3];
  for (int i = 0; i < size3; i++)
  {
    file >> arr3[i];
    if (!file)
    {
      std::cout << "Error while reading file" << "\n";
      delete[] arr3;
      return 1;
    }
  }
  try
  {
    shiftArray(arr3, size3, shift3);
    countOrderedTriples(arr3, size3);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << "Error: ";
    std::cout << e.what();
    delete[] arr3;
    return 1;
  }
  delete[] arr3;

  return 0;
}
