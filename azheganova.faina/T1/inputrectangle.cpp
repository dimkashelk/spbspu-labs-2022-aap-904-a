#include "inputrectangle.h"
#include <iostream>

point_t* inputRectangle(std::istream &in)
{
  point_t {x1};
  point_t {y1};
  point_t {x2};
  point_t {y2};
  in >> x1;
  in >> y1;
  in >> x2;
  in>> y2;
  if (!in)
  {
    std::cout << "error";
  }
  return new point_t[4]{x1, y1, x2, y2};
}
