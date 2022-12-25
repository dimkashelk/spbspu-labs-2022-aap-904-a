#include <iostream>
#include "ArrayOperations.h"

int main()
{
  //Task 1
  int arr[] = { -5, 3, -8, 5, 5, -8, 9 };
  unsigned int size = 7;
  unsigned int n = 2;
  unsigned int m = 4;

  std::cout << "Max number on even position: " << maxEven(arr, size) << '\n';
  shiftByIndexes(arr, size, n, m);
  printArray(arr, size);
}
