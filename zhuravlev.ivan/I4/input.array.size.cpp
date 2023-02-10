#include "input.array.size.h"
#include <iostream>

void inputArraySize(size_t nRows, size_t nColomns)
{
  if ((nRows <= 0) || (nColomns <= 0))
  {
    std::cout << "Wrong input!\n";
  }
  if (nRows != nColomns)
  {
    std::cout << "You need to read task before enter the ratio\n";
  }
}