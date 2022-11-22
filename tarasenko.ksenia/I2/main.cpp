#include "transformarray.hpp"
#include "searchmaxinterval.hpp"
#include <iostream>
#include <cstddef>
#include <fstream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Incorrect data entered\n";
    return 2;
  }
  int arr1[] = { 4,6,7,-2,0,5,-1 };
  transformArray(arr1, 7);
  std::cout << std::endl;
  int start_interval = 1;
  int end_interval = 9;
  int max_interval = start_interval - 1;
  try {
    max_interval = searchMaxInterval(arr1, 7, start_interval, end_interval);
    if (max_interval != start_interval - 1) {
      std::cout << max_interval << std::endl;
    }
  }
  catch(const std::invalid_argument &e) {
    std::cout << "Error:\n ";
    std::cout << e.what();
    return 1;
  }
  size_t size_arr2 = 0;
  std::cin >> size_arr2;
  if (!std::cin){
   std::cerr << "Incorrect data entered\n";
   return 1;
  }
  int* arr2 = new int[size_arr2];
  for (size_t i = 0; i < size_arr2; i++) {
    arr2[i] = std::rand();
  }
  transformArray(arr2, size_arr2);
  std::cout << std::endl;
  try {
    max_interval = searchMaxInterval(arr2, size_arr2, start_interval, end_interval);
    if (max_interval != start_interval - 1) {
      std::cout << max_interval << std::endl;
    }

  }catch (const std::invalid_argument &e) {
    std::cout << "Error:\n ";
    std::cout << e.what();
    delete[] arr2;
    return 1;
  }
  delete[] arr2;
  std::ifstream input(argv[1]);
  if (!input.is_open()) {
    std::cout << "Error while opening file";
    return 1;
  }
  size_t size_arr3 = 0;
  input >> size_arr3;
  if (!input) {
    std::cout << "Error while reading file\n";
    return 1;
  }
  if (size_arr3){
    while (!input.eof()) {
      int* arr3 = new int[size_arr3];
      for (size_t i = 0; i < size_arr3; ++i) {
        input >> arr3[i];
        if (!input) {
          std::cout << "Error while reading file\n";
          delete[] arr3;
          return 1;
        }
      }
      transformArray(arr3, size_arr3);
      std::cout << std::endl;
      try {
        max_interval = searchMaxInterval(arr3, size_arr3, start_interval, end_interval);
        if (max_interval != start_interval - 1) {
           std::cout << max_interval << std::endl;
        }
      }catch (const std::invalid_argument& e) {
        std::cout << "Error:\n ";
        std::cout << e.what();
        delete[] arr3;
        return 1;
      }
      delete[] arr3;
      input >> std::ws;
    }
  }
}
