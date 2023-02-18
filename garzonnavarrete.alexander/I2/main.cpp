#include <iostream>
#include "countAriNum.h"
#include "countIndices.h"
#include <stdexcept>
#include <cstddef>
#include <ctime>
#include <fstream>

int main(int argc, char *argv[]) {

  if (argc > 2) {
    std::cout << "Too many parameters\n";
    return 1;
  }

  int arr1[] = {2, 4, 6, 8, 10, 12, 14};
  try {
    std::cout << countIndices(arr1, 7) << std::endl;
    std::cout << countAriNum(arr1, 7) << std::endl;
  }
  catch (const std::overflow_error &e) {
    std::cout << e.what();
    return 2;
  }

  // Initialize array 2 and call the functions
  size_t n = 0;
  std::cin >> n;
  if (n == 0) {
    std::cout << "Array length cannot be 0\n";
    return 2;
  }

  int *arr2 = new int[n];
  std::srand(time(nullptr));
  for (size_t i = 0; i < n; i++) {
    arr2[i] = std::rand();
  }
  try {
    std::cout << countIndices(arr2, n) << std::endl;
    std::cout << countAriNum(arr2, n) << std::endl;
  }
  catch (const std::overflow_error &e) {
    std::cout << e.what();
    delete[] arr2;
    return 2;
  }
  delete[] arr2;

  if (argc == 1) {
    std::cout << "No input file provided\n";
    return 1;
  }

  std::ifstream in(argv[1]);
  if (!in.is_open()) {
    std::cout << "Error while opening file\n";
    return 1;
  }

  size_t size = 0;
  in >> size;
  if (!in) {
    std::cout << "Error reading file\n";
    return 1;
  }

  if (size == 0) {
    std::cout << "Array length from file cannot be 0\n";
    return 2;
  }

  int *arr = new int[size];
  for (size_t i = 0; i < size; i++) {
    in >> arr[i];
    if (!in) {
      std::cout << "Error reading file\n";
      delete[] arr;
}
}
  return 1;
}
