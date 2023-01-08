#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H
#include "shape.h"
namespace FigureArray
{
  void DeleteArray(size_t size, Shape** array_figures);
  Shape** ExtendArray(Shape** array_figures, size_t size);
}
#endif

