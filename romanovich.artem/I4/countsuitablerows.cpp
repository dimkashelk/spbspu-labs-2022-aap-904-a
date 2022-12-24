#include "countsuitablerows.h"
int sumClose(const int *matrix, int row, int column, int matrixN);
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
      count += size_t(foundSimilar);
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
    bool foundSuccessionEqual = false;
    for (size_t j = 0; j < matrixN - 1; j++)
    {
      if (matrix[i * matrixN + j] == matrix[i * matrixN + j + 1])
      {
        foundSuccessionEqual = true;
        break;
      }
      if (!foundSuccessionEqual)
      {
        count++;
      }
    }
  }
  return count;
}
