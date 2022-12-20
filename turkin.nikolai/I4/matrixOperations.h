#ifndef MATRIXOPERATIONS_H
#define MATRIXOPERATIONS_H
#include <cstddef>
#include "matrixReadWrite.h"
namespace turkin
{
  size_t getNotZeroLines(const int * matrix, size_t mx, size_t my);
  size_t getSameSumLines(const int * matrix, size_t mx, size_t my);
  size_t getSaddlePoints(int * matrix, size_t mx, size_t my);
  size_t getSumOfModules(int * matrix, size_t mx, size_t my);
  int getSumOfLine(const int * matrix, size_t mx, size_t my, size_t line);
  int * getSmoothedMatrix(const int * matrix, size_t mx, size_t my);
}
#endif
