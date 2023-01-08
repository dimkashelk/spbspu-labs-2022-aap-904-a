#include "expandArray.h"
void expandArray(Shape **&shapes, size_t size)
{
  size_t capacity = size + 1;
  Shape** newShapes = new Shape*[capacity];
  if (size > 0) {
    for (size_t i = 0; i < size; i++) {
      newShapes[i] = shapes[i];
    }
  }
  delete [] shapes;
  shapes = newShapes;
}

