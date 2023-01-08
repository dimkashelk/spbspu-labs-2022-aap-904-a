#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H
#include "shape.h"
#include <cstddef>
namespace FigureArray
{
  void DeleteArray(size_t size, Shape** array_figures);
  void ExtendArray(Shape** &array_figure, Shape* figure, size_t size);
}
#endif

