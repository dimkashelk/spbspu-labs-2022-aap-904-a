#include <iostream>
#include <fstream>
#include <cstring>
#include "scanMatrix.h"
#include "localMinima.h"
#include "sumOfModules.h"
int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "nooooooooooo" << "\n";
    return 1;
  }
  std::ofstream out_stream(argv[3]);
  if (!out_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int matrix[1000];
    size_t n = 0;
    size_t m = 0;
    std::ifstream in_stream(argv[2]);
    if (!in_stream.is_open())
    {
      std::cerr << "errrr" << "\n";
      return 1;
    }
    if (!scanSize(in_stream, n, m))
    {
      std::cerr<< "((" << "\n";
      return 2;
    }
    if (n * m > 1000)
    {
      std::cerr << "beda" << "\n";
      return 2;
    }
    try
    {
      scanMatrix(matrix, in_stream, n, m);
      out_stream << countRowsWithZeros(n, m, matrix) << "\n";
      return 0;
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "error" << "\n";
      return 2;
    }
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    size_t n = 0;
    size_t m = 0;
    std::ifstream in_stream(argv[2]);
    if (!in_stream.is_open())
    {
      std::cerr << "=()" << "\n";
      return 1;
    }
    if (!scanSize(in_stream, n, m))
    {
      std::cerr << "((" << "\n";
      return 2;
    }
    int *matrix = nullptr;
    try
    {
      matrix = new int[n * m];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "brr...memory" << "\n";
      return 1;
    }
    try
    {
    scanMatrix(matrix, in_stream, n, m);
    int *s_matrix = smoothedMatrix(matrix, n, m);
      if (s_matrix != nullptr)
      {
        out_stream << sum(s_matrix, n);
        delete[] s_matrix;
      }
      delete[] matrix;
      return 0;
    }
    catch(const std::bad_alloc &e)
    {
      std::cerr << "=()" << "\n";
      delete[] matrix;
      return 2;
    }
  }
  else
  {
    std::cerr << "brrr...." << "\n";
    return 1;
  }
  std::cerr << "<3" << "\n";
  return 0;
}
