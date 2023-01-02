#ifndef T1_INPUT_SHAPES_H
#define T1_INPUT_SHAPES_H
#include "rectangle.h"
#include "regular.h"
#include "polygon.h"
#include "compositeshape.h"
namespace dimkashelk
{
  Rectangle* inputRectangle(std::istream &in);
  Regular* inputRegular(std::istream &in);
  Polygon* inputPolygon(std::istream &in);
}
#endif
