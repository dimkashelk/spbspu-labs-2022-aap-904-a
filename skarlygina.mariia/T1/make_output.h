#ifndef MAKE_OUTPUT_H
#define MAKE_OUTPUT_H
#include "shape.h"
#include <ostream>
namespace makeOutput
{
  void makeOutputSumm(std::ostream& out, Shape** array_figures, size_t size);
  void makeOutputPosition(std::ostream& out, Shape* figure);
}
#endif
