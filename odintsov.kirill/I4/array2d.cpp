#include <cstddef>

unsigned getColAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols)
{
  unsigned colsThreeRepeat = 0;
  for (size_t i = 0; i < cols; i++) {
    for (size_t j = 0; j < rows - 2; j++) {
      int val = arr[j * rows + i];
      unsigned short count = 1;
      for (size_t k = j + 1; k < rows; k++) {
        if (val == arr[k * rows + i]) {
          count++;
          if (count == 3) {
            break;
          }
        }
      }
      if (count == 3) {
        colsThreeRepeat++;
        break;
      }
    }
  }
  return colsThreeRepeat;
}

unsigned getRowAmtThreeRepeatVals(const int*, size_t, size_t)
{
  return 0;
}
