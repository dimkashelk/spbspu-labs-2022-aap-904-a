#ifndef SPBSPU_LABS_2022_AAP_904_A__INPUT_SHAPES_H
#define SPBSPU_LABS_2022_AAP_904_A__INPUT_SHAPES_H
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
