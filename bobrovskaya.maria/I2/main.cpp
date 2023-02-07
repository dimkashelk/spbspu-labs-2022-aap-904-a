#include <iostream>
#include <fstream>
#include <cstddef>
#include "CountIndenticalElements.h"
#include "SortingArrFromNegativeToPositiveVal.h"

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    std::cout << "Incorrect number of arguments" << "\n";
    return 1;
  }

  int arr1[10] = {8, 8, 4, 6, -4, -3, 2, 5, 3, 9};
  size_t arrSize1 = 10;
  size_t maxCountIndeticEllementsArr1 = countIndenticalElements(arr1,arrSize1);
  std::cout << "The number of indentical elements in array1: " << maxCountIndeticEllementsArr1 << "\n";
  SortingArrFromNegativeToPositiveVal (arr1, arrSize1);
  std::cout << "Modified array1: ";
  for (size_t i = 0; i < arrSize1; i++)
  {
    std::cout << arr1[i];
  }
  std::cout << "\n";

  size_t arrSize2 = 0;
  int* arr2 = nullptr;
  std::cout << "Enter the size array2:";
  std::cin >> arrSize2;
  if (arrSize2 > 0)
  {
    arr2 = new int[arrSize2];
    std::srand(time(nullptr));
    for (size_t i = 0; i < arrSize2; i++)
    {
      arr2[i] = rand() % 10;
    }
    size_t maxCountIndeticEllementsArr2 = countIndenticalElements(arr2,arrSize2);
    std::cout << "The number of indentical elements in array2: " << maxCountIndeticEllementsArr2 << "\n";
    SortingArrFromNegativeToPositiveVal (arr2, arrSize2);
    std::cout << "Modified array2: ";
    for (size_t i = 0; i < arrSize2; i++)
    {
      std::cout << arr2[i];
    }
    std::cout << "\n";
    delete[] arr2;
  }

  std::ifstream readFile(argv[1]);
  if (!readFile)
  {
    std::cerr << "Invalid array size\n";
    return 2;
  }
  size_t arrSize3 = 0;
  readFile >> arrSize3;
  if (!readFile)
  {
    std::cerr << "Invalid number of array elements\n";
    return 3;
  }

  if (arrSize3 == 0)
  {
    return 0;
  }
  int* arr3 = new int[arrSize3];
  if (readFile.is_open())
  {
    while (!readFile.eof())
    {
      for (size_t i = 0; i < arrSize3; i++)
      {
        int value = 0;
        readFile >> value;
        if (!readFile)
        {
          std::cerr << "Invalid number of array elements\n";
          delete[] arr3;
          return 4;
        }
        arr3[i] = value;
      }
      readFile >> std::ws;
    }
  }
  readFile.close();
  size_t maxCountIndeticEllementsArr3 = countIndenticalElements(arr3,arrSize3);
  std::cout << "The number of indentical elements in array3: " << maxCountIndeticEllementsArr3 << "\n";
  SortingArrFromNegativeToPositiveVal (arr3, arrSize3);
  std::cout << "Modified array3: ";
  for (size_t i = 0; i < arrSize3; i++)
  {
    std::cout << arr3[i];
  }
  std::cout << "\n";
  delete[] arr3;
}

