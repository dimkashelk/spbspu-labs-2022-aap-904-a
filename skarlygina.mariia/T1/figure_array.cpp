#include "figure_array.h"
#include <stdexcept>
Shape** makeArrayFigures(size_t& capacity, size_t& size, Shape* figure, Shape** previous_array)
{
  if (capacity < size)
  {
    throw std::invalid_argument("Expansion is impossible.");
  }
  Shape** new_array = new Shape * [capacity + 2];
  capacity += 2;
  for (size_t i = 0; i <= size; ++i)
  {
    new_array[i] = previous_array[i];
  }
  delete[] previous_array;
  new_array[size] = figure;
  size++;
  return new_array;
}
