#include "check_lower_triangular_matrix.h"

bool checkLowerTriangularMatrix(const int * array, size_t size)
{
  bool is_lower_triangle = true;
  for (int i = 0; i < size; i++)
  {
    for (int j = i + 1; j < size; j++)
    {
      if (array[size * i + j] != 0)
      {
        return !(is_lower_triangle);
      }
    }
  }
  return is_lower_triangle;
}
