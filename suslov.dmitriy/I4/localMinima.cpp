#include "localMinima.h"
#include <iostream>
bool scanMatrixOne(int matrix[30][30], std::istream &in_stream, size_t &n, size_t &m)
{
  if (!in_stream.eof())
  {
    in_stream >> n;
  }
  else
  {
    return false;
  }
  if (!in_stream.eof())
  {
    in_stream >> m;
  }
  else
  {
    return false;
  }
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (!in_stream.eof())
      {
        in_stream >> matrix[i][j];
      }
      else
      {
        return false;
      }
    }
  }
  return true;
}
unsigned int counterZero(int matrix[30][30], size_t n, size_t m)
{
  unsigned int k = 0;
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      if (matrix[i][j] == 0)
      {
        k++;
        break;
      }
    }
  }
  return k;
}
