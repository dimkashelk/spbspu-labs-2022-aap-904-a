#include <iostream>
#include <fstream>
#include <cstddef>
#include "GetMaxCountSameNumbersSeq.h"
#include "ShiftArrayElements.h"

int main(int argc, char **argv)
{
  if (argc != 2) {
     std::cout << "Incorrect number of arguments" << "\n";
     return 1;
  }

  int shift = 0;
  std::cout << "How many elements do you want to shift the arrays by?\n";
  std::cin >> shift;

  // Static array
  size_t arraySize1 = 10;
  int array1[10] = {5, 2, 2, 2, 7, 7, 6, 9, 5, 2};
  // Task 6
  int maxCountSameNumbersNearby1 = getMaxCountSameNumbersSeq(array1, arraySize1);
  std:: cout << "Array1. Count of same elements nearby: " << maxCountSameNumbersNearby1 << "\n";
  // Task 7
  std:: cout << "Array1 with the specified shift: " << "\n";
  bool shiftIsPossible1 = shiftArrayElements(array1, arraySize1, shift);
  if (!shiftIsPossible1) {
    std::cout << "Shift more or equal then size of array1.\n";
  } else {
    for (size_t i = 0; i < arraySize1; ++i) {
      std::cout << array1[i] << " ";
    }
    std::cout << "\n\n";
  }

  // Dynamic array
  size_t arraySize2 = 0;
  int* array2 = nullptr;
  std::cout << "Enter the array2 size:";
  std::cin >> arraySize2;
  if (arraySize2 > 0) {
    array2 = new int[arraySize2];
    std::srand(time(nullptr));
    for (size_t i = 0; i < arraySize2; i++) {
      array2[i] = rand() % 10;
    }

    for (size_t i = 0; i < arraySize2; ++i) {
      std::cout << array2[i] << " ";
    }

    // Task 6
    int maxCountSameNumbersNearby2 = getMaxCountSameNumbersSeq(array2, arraySize2);
    std:: cout << "Array2. Count of same elements nearby: " << maxCountSameNumbersNearby2 << "\n";
    // Task 7
    std:: cout << "Array2 with the specified shift: " << "\n";
    bool shiftIsPossible2 = shiftArrayElements(array2, arraySize2, shift);
    if (!shiftIsPossible2) {
      std::cout << "Shift more or equal then size of array2.\n";
    } else {
      for (size_t i = 0; i < arraySize2; ++i) {
        std::cout << array2[i] << " ";
      }
      std::cout << "\n\n";
    }
    delete[] array2;
  }

  // Dynamic array and file
  std::ifstream fileIn(argv[1]);
  if (!fileIn) {
    std::cerr << "Invalid array size. File is empty!\n";
    return 2;
  }
  size_t arraySize3 = 0;
  fileIn >> arraySize3;
  if (!fileIn) {
    std::cerr << "Invalid number of array elements. File is empty!\n";
    return 3;
  }

  if (arraySize3 == 0) {
    return 0;
  }
  int* array3 = new int[arraySize3];
  if (fileIn.is_open()) {
    while (!fileIn.eof()) {
      for (size_t i = 0; i < arraySize3; i++) {
        int item = 0;
        fileIn >> item;
        if (!fileIn) {
          std::cerr << "Invalid number of array elements\n";
          delete[] array3;
          return 4;
        }
        array3[i] = item;
      }
      fileIn >> std::ws;
    }
  }
  fileIn.close();
  // Task 6
  int maxCountSameNumbersNearby3 = getMaxCountSameNumbersSeq(array3, arraySize3);
  std:: cout << "Array3. Count of same elements nearby: " << maxCountSameNumbersNearby3 << "\n";
  // Task 7
  std:: cout << "Array3 with the specified shift: " << "\n";
  bool shiftIsPossible3 = shiftArrayElements(array3, arraySize3, shift);
  if (!shiftIsPossible3) {
    std::cout << "Shift more or equal then size of array3.\n";
  } else {
    for (size_t i = 0; i < arraySize3; ++i) {
      std::cout << array3[i] << " ";
    }
    std::cout << "\n\n";
  }
  delete[] array3;
}
