#ifndef T1_ELLIPSE_H
#define T1_ELLIPSE_H
#include "shape.h"
#include "triangle.h"
namespace dimkashelk
{
  class Ellipse: public Shape
  {
  public:

  private:
    Triangle *triangle;
  };
}
#endif
