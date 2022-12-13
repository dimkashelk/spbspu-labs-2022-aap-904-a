#include "count_diagonals_without_zeros.h"
unsigned int countDiagonalsWithoutZeros(const int** array, size_t rows, size_t columns)
{
  unsigned int count = 0;
  if (rows < columns)
  {
   columns = rows;
  }
  else if (columns < rows)
  {
   rows = columns;
  }

  for (size_t j = 0; j < columns; j++)
  {
   bool flag = false;
   bool flag_reverse = false;
   size_t i = 0;
   size_t j_fl = j;
   size_t i_reverse = rows - i - 1;
   size_t j_reverse = rows - j_fl - 1;
   while (i != j)
   {
     if (array[i][j_fl] == '0')
     {
      flag = true;
      break;
     }
     if (array[i_reverse][j_reverse] == '0')
     {
      flag_reverse = true;
      break;
     }
     i++;
     j_fl--;
     i_reverse--;
     j_reverse++;
   }
   if (!flag)
   {
    count++;
   }
   if (!flag_reverse)
   {
    count++;
   }
  }
  return count;
}
