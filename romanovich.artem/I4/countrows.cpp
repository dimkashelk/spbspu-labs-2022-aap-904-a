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
size_t countSuccessionEqualElements(const int *matrix, size_t matrixSize)
{
  size_t count = 0;
  for (size_t i = 0; i < matrixSize; i++)
  {
    for (size_t j = 0; j < matrixSize; j++)
    {
      bool foundSuccessionEqual = false;
      if (matrix[i * matrixSize + j] == matrix[i * matrixSize + j + 1])
      {
        foundSuccessionEqual = true;
        break;
      }
      count += !foundSuccessionEqual;
    }
  }
  return count;
}
int sumClose(const int *matrix, size_t row, size_t column, size_t matrixSize)
{
  int sum_ = 0;
  std::cout << matrix[row * matrixSize + column] << "\n";
  for (int k = row-1; k <= row+1; ++k)
  {
    for (int l = column-1; l <= column+1; ++l)
    {
      if ((k*matrixSize+l >= 0) && (k*matrixSize+l <= matrixSize*matrixSize) && !(k==row && l==column))
      {
        sum_ += matrix[k * matrixSize + l];
        std::cout << matrix[k * matrixSize + l] << " ";
      }
    }
  }
  std::cout << "\n\n";
  return sum_;
}
const int smoothMatrix(const int *matrix, size_t matrixSize)
{
  int smoothedMatrix[matrixSize*matrixSize];
  for (size_t i = 0; i < matrixSize; i++)
  {
    for (size_t j = 0; j < matrixSize; j++)
    {
      smoothedMatrix[i * matrixSize + j] = sumClose(matrix, i, j, matrixSize);
    }
  }
  return *smoothedMatrix;
}
