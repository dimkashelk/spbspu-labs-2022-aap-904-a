#include "sumOfModules.h"
int *scanMatrixTwo(std::istream& in_stream, size_t &n, size_t &m)
{
  if (in_stream >> n)
  {
    if (n == 0)
    {
      return nullptr;
    }
  }
  else
  {
    return nullptr;
  }
  if (in_stream >> m)
  {
    if (m == 0)
    {
      return nullptr;
    }
  }
  else
  {
    return nullptr;
  }
  int *matrix;
  try
  {
    matrix = new int[n * m];
  }
  catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (in_stream)
      {
        in_stream >> matrix[i * n + j];
      }
      else
      {
        delete[] matrix;
        return nullptr;
      }

    }
  }
  return matrix;
}
int *smoothedMatrix(int *matrix, size_t n, size_t m)
{
  int *matrixSmoothed;
  try
  {
    matrixSmoothed = new int[n * m];
  } catch (const std::bad_alloc &e)
  {
    return nullptr;
  }
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      int sum = 0;
      for (size_t k = std::max< size_t >(i - 1, 0); k < std::min< size_t >(i + 1, n); ++k)
      {
        for (size_t l = std::max< size_t >(j - 1, 0); l < std::min< size_t >(j + 1, m); ++l)
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
int sum(int *matrix, size_t n)
{
  int sum = 0;
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < i; ++j)
    {
      sum += matrix[i * n + j];
    }
  }
  return sum;
}
