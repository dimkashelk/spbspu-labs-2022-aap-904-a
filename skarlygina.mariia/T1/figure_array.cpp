#include "figure_array.h"
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