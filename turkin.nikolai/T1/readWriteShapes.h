#ifndef T1_READWRITESHAPES_H
#define T1_READWRITESHAPES_H
#include <istream>
#include "rectangle.h"
#include "ellipse.h"
namespace turkin
{
   Rectangle * createRectangle(std::istream & input);
   Rectangle * createSquare(std::istream & input);
   Ellipse * createEllipse(std::istream & input);
   scale_t getScale(std::istream & input);
   void printAreaPoints(std::ostream & output, Shape ** shapes, size_t size);
}
#endif

