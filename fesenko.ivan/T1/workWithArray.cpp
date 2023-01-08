#include "workWithArray.h"

void expandArray(Shape **&shapes, size_t size)
{
  size_t capacity = size + 1;
  Shape** newShapes = new Shape*[capacity];
  for (size_t i = 0; i < size; i++) {
    newShapes[i] = shapes[i];
  }
  delete [] shapes;
  newShapes[size] = nullptr;
  shapes = newShapes;
}

void deleteArray(Shape **shapes, size_t size)
{
  for (size_t i = 0; i < size; i++) {
    delete shapes[i];
  }
  delete [] shapes;
}

