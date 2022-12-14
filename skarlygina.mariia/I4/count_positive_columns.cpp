#include "count_positive_columns.h"
size_t countPositiveColumns(int** array, size_t rows, size_t columns)
{
  size_t number_of_positive_columns = 0;
  size_t i = 0;
  if (rows && columns)
  {
    while (i < columns)
    {
      bool flag = false;
      for (size_t j = 0; j < rows; j++)
      {
        if (array[j][i] <= 0)
        {
          flag = true;
          break;
        }
      }
      if (!flag)
      {
        number_of_positive_columns += 1;
      }
      i++;
    }
  }
  return number_of_positive_columns;
}
