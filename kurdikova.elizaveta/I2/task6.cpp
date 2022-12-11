#include "task6.h"

int getMaxCountSameNumbersSeq(int* arr, int size)
{
  int maxCount = 1;
  int currentCount = 1;
  for (int i = 0; i < size - 1; ++i) {
    if (arr[i] == arr[i + 1]) {
      currentCount++;
    } else if (currentCount > maxCount) {
      maxCount = currentCount;
      currentCount = 1;
    } else {
      currentCount = 1;
    }
  }
  return maxCount;
}
