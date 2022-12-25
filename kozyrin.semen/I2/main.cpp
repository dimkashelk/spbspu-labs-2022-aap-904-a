#include <iostream>
#include "ArrayOperations.h"

int main()
{
  //Task 1
  std::cout << "//Task 1 \n";

  int arr1[] = { -5, 3, -8, 5, 5, -8, 9 };
  unsigned int size = 7;
  unsigned int n = 2;
  unsigned int m = 4;

  std::cout << "Max number on even position: " << maxEven(arr1, size) << '\n';
  shiftByIndexes(arr1, size, n, m);
  printArray(arr1, size);

  //Task 2
  std::cout << "\n//Task 2 \n";

  std::cin >> size;
  int* arr2 = new int[size]{0};
  randomizeArray(arr2, size);

  std::cout << "Max number on even position: " << maxEven(arr2, size) << '\n';
  shiftByIndexes(arr2, size, n, m);
  printArray(arr2, size);

  delete[] arr2;
}
