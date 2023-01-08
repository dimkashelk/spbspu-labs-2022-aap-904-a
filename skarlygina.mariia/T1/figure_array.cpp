#include "figure_array.h"
#include <cstddef>
#include <iostream>
void FigureArray::DeleteArray(size_t size, Shape** array_figures)
{
  if (size > 0)
  {
    for (size_t i = 0; i < size; i++)
    {
      delete array_figures[i];
    }
  }
  delete[] array_figures;
}

void FigureArray::ExtendArray(Shape** &array_figure, Shape* figure, size_t size)
{
  size_t capacity = size + 1;
  Shape** array_extended = new Shape*[capacity];
  if (size > 0)
  {
    for (size_t i = 0; i < size; i++)
    {
      array_extended[i] = array_figure[i];
    }
  }
  delete[] array_figure;
  array_extended[capacity - 1] = figure;
  array_figure = array_extended;
}
