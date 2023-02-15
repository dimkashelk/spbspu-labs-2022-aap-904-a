#include <stdexcept>
#include "fillingthematrixinspiral.h"

int* fillingTheMatrixInSpiral(int* matrix, size_t c, size_t r, size_t indrow, size_t indcol)
{
  if (indrow > r || indcol > c)
  {
    throw std::invalid_argument("too big index");
  }
  indrow--;
  indcol--;
  matrix[c * indrow + indcol] = 1;
  size_t val = 1;
  size_t top = 0, bottom = r - 1, left = 0, right = c - 1;
  while (top <= bottom && left <= right)
  {
    for (size_t i = top; i <= bottom; i++)
    {
      matrix[c * i + left] = val++;
    }
    left++;
    for (size_t i = left; i <= right; i++)
    {
      matrix[c * bottom + i] = val++;
    }
    bottom--;
    if (left <= right)
    {
      for (size_t i = bottom; i >= top; i--)
      {
        matrix[c * i + right] = val++;
      }
      right--;
    }
    if (top <= bottom)
    {
      for (size_t i = right; i >= left; i--)
      {
        matrix[c * top + i] = val++;
      }
      top++;
    }
 }
  return matrix;
}
