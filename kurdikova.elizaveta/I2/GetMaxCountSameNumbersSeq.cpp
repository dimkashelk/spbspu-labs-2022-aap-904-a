#include "GetMaxCountSameNumbersSeq.h"

int getMaxCountSameNumbersSeq(const int* arr, size_t size)
{
  int maxCount = 1;
  int currentCount = 1;
  for (size_t i = 0; i < size - 1; ++i) {
    if (arr[i] == arr[i + 1]) {
      currentCount++;
    } else {
      currentCount = 1;
    }
    if (currentCount > maxCount) {
      maxCount = currentCount;
    }
  }
  return maxCount;
}
