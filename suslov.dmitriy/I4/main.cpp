#include <iostream>
#include "localMinima.h"
#include <fstream>
#include "sumOfModules.h"
int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "nooooooooooo" << "\n";
    return -1;
  }
  std::ofstream out_stream;
  out_stream.open(argv[3]);
  if (!out_stream.is_open())
  {
    std::cerr << "=(" << "\n";
    return 2;
  }
  if (argv[1][0] == '1' and argv[1][1] == '\0')
  {
    int n, m;
    bool result = scanMatrixOne(argv[2], &n, &m);
    if (result == true)
    {
      out_stream << counterZero(n, m) << "\n";
      return 0;
    }
  }
  else if (argv[1][0] == '2' and argv[1][1] == '\0')
  {
    int n, m;
    int *matrix = scanMatrixTwo(argv[2], &n, &m);
    if (matrix != nullptr)
    {
      int *s_matrix = smoothedMatrix(matrix, n, m);
      if (s_matrix != nullptr)
      {
        out_stream << sum(s_matrix, n, m);
        delete[]s_matrix;
      }
      else
      {
        std::cerr << "ohhhhh" << "\n";
        delete[]matrix;
        return -1;
      }
      delete[]matrix;
      return 0;
    }
  }
  else
  {
    std::cerr << "brrr...." << "\n";
    return -1;
  }
  std::cerr << "<3" << "\n";
  return 0;
}
