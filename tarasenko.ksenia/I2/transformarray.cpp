#include "transformarray.hpp"
#include <iostream>

void transformArray(int* arr, size_t size) {
  if (size != 0) {
    size_t n = size;
    int temp;
    for (size_t i = 0; i < size; i++) {
      if (arr[i] >= 0) {
        temp = arr[i];
        for (size_t j = i; j < size - 1; j++) {
          arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
        --size;
        --i;
      }
    }
    for (int i = 0; i < n; i++){
      std::cout << arr[i] << " ";
    }
  }
}
