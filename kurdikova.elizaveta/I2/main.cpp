#include <iostream>
#include <fstream>
#include "task6.h"
#include "task7.h"

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
  int array1[10] = {5, 2, 2, 2, 7, 7, 6, 9, 5, 2};
  // Task 6
  int result16 = getMaxCountSameNumbersSeq(array1, 10);
  std:: cout << "Array1. Task 6 result: " << result16 << std::endl;
  // Task 7
  std:: cout << "Array1. Task 7 result: " << std::endl;
  int result17 = shiftArrayElements(array1, 10, shift);
  if (result17 != 0)
  {
    std::cout << "Shift more or equal then size of array1. Error...\n";
  } else {
    for (int i : array1) {
      std::cout << i << " ";
    }
    std::cout << "\n\n";
  }

  // Dynamic array
  int arraySize2 = 0;
  int* array2 = nullptr;
  std::cout << "Enter the array2 size: ";
  std::cin >> arraySize2;
  if (arraySize2 > 0) {
    array2 = new int[arraySize2];
    std::srand(time(nullptr));
    for (int i = 0; i < arraySize2; i++) {
      array2[i] = rand() % 10;
    }
    // Task 6
    int result26 = getMaxCountSameNumbersSeq(array2, arraySize2);
    std:: cout << "Array2. Task 6 result: " << result26 << std::endl;
    // Task 7
    std:: cout << "Array2. Task 7 result: " << std::endl;
    int result27 = shiftArrayElements(array2, arraySize2, shift);
    if (result27 != 0)
    {
      std::cout << "Shift more or equal then size of array2. Error...\n";
    } else {
      for (int i = 0; i < arraySize2; ++i) {
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
  int arraySize3 = 0;
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
      for (int i = 0; i < arraySize3; i++) {
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
  int result36 = getMaxCountSameNumbersSeq(array3, arraySize3);
  std:: cout << "Array3. Task 6 result: " << result36 << std::endl;
  // Task 7
  std:: cout << "Array3. Task 7 result: " << std::endl;
  int result37 = shiftArrayElements(array3, arraySize3, shift);
  if (result37 != 0)
  {
    std::cout << "Shift more or equal then size of array3. Error...\n";
  } else {
    for (int i = 0; i < arraySize3; ++i) {
      std::cout << array3[i] << " ";
    }
    std::cout << "\n\n";
  }
  delete[] array3;
}
