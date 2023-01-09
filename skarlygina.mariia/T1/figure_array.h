#ifndef FIGURE_ARRAY_H
#define FIGURE_ARRAY_H
#include "shape.h"
#include <cstddef>
namespace FigureArray
{
  void deleteArray(size_t size, Shape** array_figures);
  void extendArray(Shape** &array_figure, Shape* figure, size_t size);
  void deleteArgument(Shape* figure, bool isCommand);
}
#endif
