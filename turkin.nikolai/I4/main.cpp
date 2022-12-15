#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cstring>
#include "matrix.h"
#include "matrixOperations.h"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "invalid amount of arguments\n";
    return 1;
  }
  size_t mx = 0;
  size_t my = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "cannot open file\n";
    return 1;
  }
  input >> mx >> my;
  if (!input)
  {
    std::cerr << "empty file\n";
    return 1;
  }
  if (mx * my > 1000)
  {
    std::cerr << "out of range\n";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    int constMatrix[1000];
    for (size_t i = 0; i < mx * my; i++)
    {
      input >> constMatrix[i];
      if (!input)
      {
        std::cerr << "memory error\n";
        return 1;
      }
    }
    std::ofstream output(argv[3]);
    output << turkin::getNotZeroLines(constMatrix, mx, my) << " " << turkin::getSameSumLines(constMatrix, mx, my);
  }
  else
  {
    turkin::Matrix dynamicMatrix(mx, my);
    turkin::set(dynamicMatrix, input);
    if (!input)
    {
      std::cerr << "memory error\n";
      return 1;
    }
    std::ofstream output(argv[3]);
    output << turkin::getSaddlePoints(dynamicMatrix) << " " << turkin::getSumOfModules(dynamicMatrix) << "\n";
  }
  return 0;
}
