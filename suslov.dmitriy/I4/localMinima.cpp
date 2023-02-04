#include "localMinima.h"
#include <fstream>
#include <iostream>
int matrix[1000][1000];
bool scanMatrixOne(const char *in_file, int *n, int *m)
{
  std::ifstream in_stream;
  in_stream.open(in_file);
  if (!in_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return false;
  }
  if (!in_stream.eof())
  {
    in_stream >> *n;
  }
  else
  {
    return false;
  }
  if (!in_stream.eof())
  {
    in_stream >> *m;
  }
  else
  {
    return false;
  }
  for (int i = 0; i < *n; ++i)
  {
    for (int j = 0; j < *m; ++j)
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
unsigned int counterZero(int n, int m)
{
  unsigned int k = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < m; ++j)
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
