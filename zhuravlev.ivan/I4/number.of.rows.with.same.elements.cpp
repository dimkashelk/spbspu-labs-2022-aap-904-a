#include "number.of.rows.with.same.elements.h"

int counterOfRowsWithSameElements(int* arr, size_t nRows, size_t nColomns)
{
  int cnt = 0;
  for (int i = 0; i < nRows; ++i)
  {
    for (int j = 0; j < nColomns; ++j)
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
