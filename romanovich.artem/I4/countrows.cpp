#include "countrows.h"
#include <iostream>
size_t countDiverseElements(const int *array, size_t rows, size_t columns)
{
  size_t count = 0;
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < columns; j++)
    {
      bool foundSimilar = false;
      int currentEl = array[i * rows + j];
      for (size_t k = j + 1; k < columns; k++)
      {
        if (currentEl == array[i * rows + k])
        {
          foundSimilar = true;
          break;
        }
      }
      count += foundSimilar;
    }
  }
  return count;
}
size_t countEqualSum(const int *array, size_t rows, size_t columns)
{
  size_t count = 0;
  int arraySums[rows];
  for (size_t i = 0; i < rows; i++)
  {
    arraySums[i] = 0;
    for (size_t j = 0; j < columns; j++)
    {
      arraySums[i] += array[i * rows + j];
    }
  }
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = i + 1; j < rows; j++)
    {
      if (arraySums[i] == arraySums[j])
      {
        count++;
      }
    }
  }
  return count;
}
size_t countSuccessionEqualElements(const int *matrix, size_t matrixN)
{
  size_t count = 0;
  for (size_t i = 0; i < matrixN; i++)
  {
    for (size_t j = 0; j < matrixN - 1; j++)
    {
      bool foundSuccessionEqual = false;
      if (matrix[i * matrixN + j] == matrix[i * matrixN + j + 1])
      {
        foundSuccessionEqual = true;
        break;
      }
      count += !foundSuccessionEqual;
    }
  }
  return count;
}
int sumClose(const int *matrix, int row, int column, int matrixN)
{
  int sum_ = 0;
  int count = 0;
  for (int k = row-1; k <= row+1; k++)
  {
    for (int l = column-1; l <= column+1; l++)
    {
      if ((k*matrixN+l >= 0) && (k*matrixN+l <= matrixN*matrixN) && !(k==row && l==column) && 0 <= l && l < matrixN && 0 <= k && k < matrixN)
      {
        sum_ += matrix[k * matrixN + l];
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
  std::cout << "\n";
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
