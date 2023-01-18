#include "ArrayOperations.h"

void inputArray(int* arr, size_t size, std::istream& stream)
{
  for (size_t i = 0; i < size; ++i) {
    stream >> arr[i];
  }
}