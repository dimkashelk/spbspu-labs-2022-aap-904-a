#include <iostream>
#include <fstream>
#include <cstdlib>
#include "algorithms.h"

int main()
{
  const size_t arr_size = 7;
  int arr[arr_size] = {1, 9, 3, -2, -3, 2, 6};
  std::cout << negativeAfterMax(arr, arr_size) << "\n";
  movingElements(arr, arr_size);
  for (size_t i = 0; i < arr_size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
  size_t dyn_arr_size = 0;
  std::cin >> dyn_arr_size;
  if (!std::cin) {
    std::cerr << "Error while reading\n";
    return 2;
  }
  if (dyn_arr_size <= 0) {
    std::cerr << "Wrong array size\n";
    return 2;
  }
  srand(time(0));
  int *dyn_arr = new int [dyn_arr_size];
  for (size_t i = 0; i < dyn_arr_size; i++) {
    dyn_arr[i] = rand() % 100;
  }
  std::cout << negativeAfterMax(dyn_arr, dyn_arr_size) << "\n";
  movingElements(dyn_arr, dyn_arr_size);
  for (size_t i = 0; i < dyn_arr_size; i++) {
    std::cout << dyn_arr[i] << " ";
  }
  std::cout << "\n";
  delete [] dyn_arr;
  size_t file_arr_size = 0;
  std::ifstream in("file.txt");
  if (!in.is_open()) {
    std::cerr << "Can not open the file\n";
    return 2;
  }
  in >> file_arr_size;
  if (!in) {
    std::cerr << "Can not read from file\n";
    return 2;
  }
  if (file_arr_size <= 0) {
    std::cerr << "Wrong array size\n";
    return 2;
  }
  int *file_arr = new int[file_arr_size];
  for (size_t i = 0; i < file_arr_size; i++) {
    in >> file_arr[i];
    if (!in) {
      std::cerr << "Error while reading\n";
      return 2;
    }
  }
  std::cout << negativeAfterMax(file_arr, file_arr_size) << "\n";
  movingElements(file_arr, file_arr_size);
  for (size_t i = 0; i < file_arr_size; i++) {
    std::cout << file_arr[i] << " ";
  }
  std::cout << "\n";
  delete[] file_arr;
}
