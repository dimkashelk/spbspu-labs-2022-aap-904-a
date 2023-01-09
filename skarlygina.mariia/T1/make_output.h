#ifndef MAKE_OUTPUT_H
#define MAKE_OUTPUT_H
#include "shape.h"
#include <ostream>
void makeOutput(std::ostream& out, Shape* const* array_figures, size_t size);
void makeErrorOutput(std::string error, size_t size, Shape** array_figures);
#endif
