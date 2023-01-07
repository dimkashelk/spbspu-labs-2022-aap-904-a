#ifndef GETSHAPES_HPP
#define GETSHAPES_HPP

#include <istream>
#include "Shape.hpp"

Shape *makeRectangle(std::istream &input);
Shape *makeEllipse(std::istream &input);
Shape *makeConcave(std::istream &input);
scale_t calcScale(std::istream &input);


#endif
