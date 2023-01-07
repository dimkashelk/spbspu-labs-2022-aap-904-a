#ifndef CREATESHAPES_HPP
#define CREATESHAPES_HPP
#include <istream>
#include "shape.hpp"

Shape *createRectangle(std::istream &input);
Shape *createRing(std::istream &input);
Shape *createConcave(std::istream &input);
scale_t getScale(std::istream &input);

#endif
