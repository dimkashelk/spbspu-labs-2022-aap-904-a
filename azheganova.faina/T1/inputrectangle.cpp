#include "inputrectangle.h"
#include <iostream>
#include "compositeshape.h"

Shape* inputRectangle(std::istream &input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  input >> x1 >> y1 >> x2 >> y2;
  if (!input)
  {
    std::cout << "error";
  }
  return new Rectangle(point_t{x1, y1}, point_t{x2, y2});
}
