#include "smoothedmatrix.h"
int sumClose(const int *matrix, size_t row, size_t column, size_t matrixN);
int sumClose(const int *matrix, size_t row, size_t column, size_t matrixN)
{
  int sum_ = 0;
  int count = 0;
  for (size_t k = (row>0) ? row-1 : row; k <= row+1; k++)
  {
    for (size_t l = (column>0) ? column-1 : column; l <= column+1; l++)
    {
      size_t elemIndex = k*matrixN+l;
      bool elemInMatrixRange = (elemIndex <= matrixN*matrixN);
      bool elemNotCenterElem = !(k==row && l==column);
      bool kInRowRange = k < matrixN;
      bool lInColumnRange = l < matrixN;
      if (elemInMatrixRange && elemNotCenterElem && lInColumnRange && kInRowRange)
      {
        sum_ += matrix[elemIndex];
        count++;
      }
    }
  }
  return sum_ / count;
}
int countUpperMainDiagonal(const int *matrix, size_t matrixN)
{
  int sum_ = 0;
  for (size_t i = 0; i < matrixN - 1; i++)
  {
    for (size_t j = i + 1; j < matrixN; j++)
    {
      int value = matrix[i * matrixN + j];
      sum_ += value * ((value > 0) - (value < 0));
    }
  }
  return sum_;
}
void smoothMatrix(const int *matrix, int *smoothedMatrix, size_t matrixN)
{
  for (size_t i = 0; i < matrixN; i++)
  {
    for (size_t j = 0; j < matrixN; j++)
    {
      smoothedMatrix[i * matrixN + j] = sumClose(matrix, i, j, matrixN);
    }
  }
}
