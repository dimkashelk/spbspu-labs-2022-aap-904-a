#include "number_of_rows_with_same_elements.h"
#include <cstddef>

int counterOfRowsWithSameElements(int* arr, size_t nRows, size_t nColomns)
{
  int cnt = 0;
  for (size_t i = 0; i < nRows; ++i)
  {
    for (size_t j = 0; j < nColomns; ++j)
    {
      if (arr[i][j] == arr[i][j + 1])
      {
        ++cnt;
        break;
      }
    }
  }
  return cnt;
}
