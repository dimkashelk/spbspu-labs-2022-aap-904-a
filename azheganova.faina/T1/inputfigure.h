#ifndef INPUTFIGURE_H
#define INPUTFIGURE_H
#include <stdexcept>
#include "complexquad.h"
#include "rectangle.h"
#include "triangle.h"

Shape* inputRectangle(std::istream &input);
Shape* inputTriangle(std::istream &input);
Shape* inputComplexquad(std::istream &input);

#endif
