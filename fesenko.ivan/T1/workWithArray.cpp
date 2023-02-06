#include "workWithArray.h"

Shape **expandArray(Shape **shapes, size_t &capacity)
{
  size_t new_capacity = capacity + 10;
  Shape** newShapes = new Shape*[new_capacity];
  for (size_t i = 0; i < capacity; i++) {
    newShapes[i] = shapes[i];
  }
  return newShapes;
}

void deleteArray(Shape **shapes, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    delete shapes[i];
  }
  delete [] shapes;
}

