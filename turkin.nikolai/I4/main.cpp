#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <exception>
#include "matrix.h"
#include "matrixOperations.h"

int main(int argc, char * argv[]) {
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
  if (atoi(argv[1]) == 1)
  {
    try
    {
      int constMatrix[1000];
      for (size_t i = 0; i < mx * my; i++) {
        input >> constMatrix[i];
      }
      std::ofstream output(argv[3]);
      output << turkin::getNotZeroLines(constMatrix, mx, my) << " " << turkin::getSameSumLines(constMatrix, mx, my);
    }
    catch (std::bad_alloc const & error)
    {
      std::cerr << error.what() << "\n";
      return 1;
    }
  }
  else
  {
    try
    {
      turkin::Matrix dynamicMatrix(mx, my);
      turkin::set(dynamicMatrix, input);
      std::ofstream output(argv[3]);
      output << turkin::getSaddlePoints(dynamicMatrix) << " " << turkin::getSumOfModules(dynamicMatrix) << "\n";
    }
    catch (std::bad_alloc const & error)
    {
      std::cerr << error.what() << "\n";
      return 1;
    }
  }
  return 0;
}
