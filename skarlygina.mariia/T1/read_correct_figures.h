#ifndef READ_CORRECT_FIGURES_H
#define READ_CORRECT_FIGURES_H
#include "ellipse.h"
#include "ring.h"
#include "rectangle.h"
#include <istream>
namespace correctFigures
{
  Rectangle* readCorrectRectangle(std::istream& in);
  Ring* readCorrectRing(std::istream& in);
  Ellipse* readCorrectEllipse(std::istream& in);
}
#endif
