#include "second_var_one.h"
#include <fstream>
#include <iostream>
int matrix[1000][1000];
bool scanMatrix_one(const char *in_file, int *n, int *m)
{
  std::ifstream in_stream;
  in_stream.open(in_file);
  if (!in_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return false;
  }
  in_stream >> *n >> *m;
  for (int i = 0; i < *n; ++i)
  {
    for (int j = 0; j < *m; ++j)
    {
      in_stream >> matrix[i][j];
    }
  }
  return true;
}
unsigned int counter_zero(int n, int m)
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
