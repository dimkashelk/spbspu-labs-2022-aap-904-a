#include "ArrayOperations.h"

void inputArray(int* arr, size_t size, std::istream& stream)
{
  for (size_t i = 0; i < size; ++i) {
    stream >> arr[i];
  }
}

size_t sortedRowsCount(const int* arr, size_t rows, size_t cols)
{
  size_t cnt = 0;

  for (size_t i = 0; i < rows; ++i) {
    cnt++;
    for (size_t j = 0; j < cols - 1; ++j) {
      size_t offset = i * cols;
      if (arr[offset + j] > arr[offset + j + 1]){
        cnt--;
        break;
      }
    }
  }
  return cnt;
}