#ifndef T1_READSHAPES_H
#define T1_READSHAPES_H
#include <istream>
#include "rectangle.h"
#include "ellipse.h"
namespace turkin
{
   Rectangle * createRectangle(std::istream & input);
   Rectangle * createSquare(std::istream & input);
   Ellipse * createEllipse(std::istream & input);
   scale_t getScale(std::istream & input);
}
#endif
