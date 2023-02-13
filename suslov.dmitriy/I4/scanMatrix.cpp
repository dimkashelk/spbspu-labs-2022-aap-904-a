#include "scanMatrix.h"
bool scanSize(std::istream &in_stream, size_t &n, size_t &m)
{
  if (!(in_stream >> n))
  {
    return false;
  }
  if (!(in_stream >> m))
  {
    return false;
  }
  return true;
}
bool scanMatrix(int *matrix, std::istream &in_stream, const size_t n, const size_t m)
{
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
