#include "array2d.hpp"
#include <cstddef>

int odintsov::get2DArrayVal(const int* arr, size_t rows, size_t, size_t x, size_t y)
{
  return arr[y * rows + x];
}

unsigned odintsov::getColAmtThreeRepeatVals(const int* arr, size_t rows, size_t cols)
{
  unsigned colsThreeRepeat = 0;
  for (size_t i = 0; i < cols; i++) {
    for (size_t j = 0; j < rows - 2; j++) {
      int val = get2DArrayVal(arr, rows, cols, i, j);
      unsigned short count = 1;
      for (size_t k = j + 1; k < rows; k++) {
        if (val == get2DArrayVal(arr, rows, cols, i, k)) {
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

unsigned odintsov::getRowAmtThreeRepeatVals(const int*, size_t, size_t)
{
  return 0;
}
