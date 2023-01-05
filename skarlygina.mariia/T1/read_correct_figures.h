#ifndef READ_CORRECT_FIGURES_H
#define READ_CORRECT_FIGURES_H
#include "ellipse.h"
#include "ring.h"
#include "rectangle.h"
#include <istream>
namespace correctFigures
{
  Rectangle* readCorrectRectangle(std::istream& in, bool& isCorrect);
  Ring* readCorrectRing(std::istream& in, bool& isCorrect);
  Ellipse* readCorrectEllipse(std::istream& in, bool& isCorrect);
}
#endif
