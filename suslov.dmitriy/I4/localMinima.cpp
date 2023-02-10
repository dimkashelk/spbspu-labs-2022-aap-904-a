#include "localMinima.h"
#include <iostream>
bool scanMatrixOne(int *matrix, std::istream &in_stream, size_t &n, size_t &m)
{
  if (!(in_stream >> n))
  {
    return false;
  }
  if (!(in_stream >> m))
  {
    return false;
  }
  if (n * m >1000)
  {
    return false;
  }
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (!(in_stream >> matrix[i * n + j]))
      {
        return false;
      }
    }
  }
  return true;
}
size_t counterZero(const size_t n, const size_t m, const int *matrix)
{
  size_t k = 0;
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (matrix[i * n + j] == 0)
      {
        k++;
        break;
      }
    }
  }
  return k;
}
