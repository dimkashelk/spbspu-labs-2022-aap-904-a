#ifndef READ_CORRECT_FIGURES_H
#define READ_CORRECT_FIGURES_H
#include "shape.h"
#include <istream>
namespace correctFigures
{
  Shape* readCorrectRectangle(std::istream& in);
  Shape* readCorrectRing(std::istream& in);
  Shape* readCorrectEllipse(std::istream& in);
}
#endif
