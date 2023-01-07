#ifndef MAKESHAPES_HPP
#define MAKESHAPES_HPP

#include <istream>
#include "Shape.hpp"

Shape *makeRectangle(std::istream &input);
Shape *makeEllipse(std::istream &input);
Shape *makeConcave(std::istream &input);
scale_t getScale(std::istream &input);

#endif
