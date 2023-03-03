#include "numberRowsNoConcecutiveIndeticalElements.h"

int numberRowsNoConcecutiveIndeticalElements(int *matrix, size_t rows, size_t colomn)
{
  size_t count = 0;
  size_t countElements = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < colomn - 1; j++)
    {
      if (matrix[i * colomn + j] == matrix[i * colomn + j + 1])
        {
          countElements++;
          break;
        }
    }
    if (countElements == 0)
    {
      count++;
    }
    countElements = 0;
  }
  return count;
}
