#include <iostream>
#include <fstream>
#include <cstring>
#include "localMinima.h"
#include "sumOfModules.h"
int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "nooooooooooo" << "\n";
    return 1;
  }
  std::ofstream out_stream;
  out_stream.open(argv[3]);
  if (!out_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return 1;
  }
  if (strcmp(argv[1], "1") == 0)
  {
    int matrix[30][30];
    size_t n = 0;
    size_t m = 0;
    std::ifstream in_stream;
    in_stream.open(argv[2]);
    if (!in_stream.is_open())
    {
      std::cerr << "errrr" << "\n";
      return 1;
    }
    bool result = scanMatrixOne(matrix, in_stream, n, m);
    if (result == true)
    {
      out_stream << counterZero(matrix, n, m) << "\n";
      return 0;
    }
    else
    {
      std::cerr << "errrr" << "\n";
      return 2;
    }
  }
  else if (strcmp(argv[1], "2") == 0)
  {
    size_t n = 0;
    size_t m = 0;
    std::ifstream in_stream;
    in_stream.open(argv[2]);
    if (!in_stream.is_open())
    {
      std::cerr << "=()" << "\n";
      return 1;
    }
    int *matrix = scanMatrixTwo(in_stream, n, m);
    if (matrix != nullptr)
    {
      int *s_matrix = smoothedMatrix(matrix, n, m);
      if (s_matrix != nullptr)
      {
        out_stream << sum(s_matrix, n);
        delete[] s_matrix;
      }
      else
      {
        std::cerr << "ohhhhh" << "\n";
        delete[] matrix;
        return 2;
      }
      delete[] matrix;
      return 0;
    }
    else
    {
      std::cerr << "=()" << "\n";
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
