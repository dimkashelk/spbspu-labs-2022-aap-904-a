#include "islowertrianglematrix.hpp"
#include <cstddef>

bool isLowerTriangleMatirix(const int* array, const size_t rows, const size_t columns)
{
  for (size_t i = 0; i < rows; i++) 
  {
    for (size_t j = 0; j < columns; j++) 
    {
      if ((j > i) && (array[i * columns + j] != 0)) 
      {
        return false;
      }
    }
  }
  return true;
}
