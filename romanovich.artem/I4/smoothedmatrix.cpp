#include "smoothedmatrix.h"
int sumClose(const int *matrix, int row, int column, int matrixN);
int sumClose(const int *matrix, int row, int column, int matrixN)
{
  int sum_ = 0;
  int count = 0;
  for (int k = row-1; k <= row+1; k++)
  {
    for (int l = column-1; l <= column+1; l++)
    {
      int elemIndex = k*matrixN+l;
      bool elemInMatrixRange = (elemIndex >= 0) && (elemIndex <= matrixN*matrixN);
      bool elemNotCenterElem = !(k==row && l==column);
      bool kInRowRange = (0 <= k && k < matrixN);
      bool lInColumnRange = (0 <= l && l < matrixN);
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
