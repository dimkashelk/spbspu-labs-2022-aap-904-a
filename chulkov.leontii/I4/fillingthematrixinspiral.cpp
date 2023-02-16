#include "fillingthematrixinspiral.h"
#include <stdexcept>

int* fillingTheMatrixInSpiral(int* matrix, size_t c, size_t r, size_t indrow, size_t indcol)
{
  if (indrow > r || indcol > c)
  {
    throw std::invalid_argument("too big index");
  }
  indrow--;
  indcol--;
  matrix[c * indrow + indcol] = 1;
  int val = 1;
  int top = 0, bottom = r - 1, left = 0, right = c - 1;
  while (top <= bottom && left <= right)
  {
    for (int i = top; i <= bottom; i++)
    {
      matrix[c * i + left] = val++;
    }
    left++;
    for (int i = left; i <= right; i++)
    {
      matrix[c * bottom + i] = val++;
    }
    bottom--;
    if (left <= right)
    {
      for (int i = bottom; i >= top; i--)
      {
        matrix[c * i + right] = val++;
      }
      right--;
    }
    if (top <= bottom)
    {
      for (int i = right; i >= left; i--)
      {
        matrix[c * top + i] = val++;
      }
      top++;
    }
 }
  return matrix;
}
