#ifndef T1_INPUT_SHAPES_H
#define T1_INPUT_SHAPES_H
#include "rectangle.h"
#include "regular.h"
#include "polygon.h"
#include "compositeshape.h"
namespace dimkashelk
{
  Rectangle* input_rectangle(std::istream &in);
  Regular* input_regular(std::istream &in);
  Polygon* input_polygon(std::istream &in);
}
#endif
