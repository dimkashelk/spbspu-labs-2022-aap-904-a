#include "sumOfModules.h"
#include <fstream>
int *scanMatrixTwo(const char *in_file, int *n, int *m)
{
  std::ifstream in_stream;
  in_stream.open(in_file);
  if (!in_stream.is_open())
  {
    return nullptr;
  }
  in_stream >> *n >> *m;
  int *matrix;
  try
  {
    matrix = new int[(*n) * (*m)];
  } catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  for (int i = 0; i < *n; ++i)
  {
    for (int j = 0; j < *m; ++j)
    {
      in_stream >> matrix[i * (*n) + j];
    }
  }
  return matrix;
}
int *smoothedMatrix(int *matrix, int n, int m)
{
  int *matrixSmoothed;
  try
  {
    matrixSmoothed = new int[n * m];
  } catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
    {
      int sum = 0;
      for (int k = std::max(i - 1, 0); k < std::min(i + 1, n); ++k)
      {
        for (int l = std::max(j - 1, 0); l < std::min(j + 1, m); ++l)
        {
          if (k != i or l != j)
          {
            sum += matrix[k * n + l];
          }
        }
      }
      matrixSmoothed[i * n + j] = sum;
    }
  }
  return matrixSmoothed;
}
int sum(int *matrix, int n)
{
  int sum = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < i; ++j)
    {
      sum += matrix[i * n + j];
    }
  }
  return sum;
}
