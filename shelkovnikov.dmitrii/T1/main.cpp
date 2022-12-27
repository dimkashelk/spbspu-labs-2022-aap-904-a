#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstddef>
#include "rectangle.h"
void expand(Shape **shapes, size_t size, size_t new_capacity)
{
  if (new_capacity < size)
  {
    throw std::runtime_error("New capacity less size");
  }
  Shape **new_shapes = new Shape*[new_capacity];
  for (size_t i = 0; i < size; i++)
  {
    new_shapes[i] = shapes[i];
  }
  delete[] shapes;
  shapes = new_shapes;
}
Rectangle input_rectangle(std::istream &in)
{
  double *coords = new double[4];
  for (size_t i = 0; i < 4; i++)
  {
    in >> coords[i];
    if (!in)
    {
      throw std::runtime_error("Not enough data to input");
    }
  }
  return Rectangle(coords[0], coords[1], coords[2], coords[3]);
}
int main()
{
  std::string line = "";
  std::string name = "";
  bool contains_errors_with_shapes = false;
  size_t size = 0;
  size_t capacity = 10;
  Shape **shapes = new Shape*[capacity];
  while (std::cin)
  {
    std::getline(std::cin, line);
    std::istringstream in(line);
    in >> name;
    if (name == "RECTANGLE")
    {
      try
      {
        Rectangle rect = input_rectangle(in);
        shapes[size] = &rect;
        size++;
        if (size == capacity)
        {
          capacity += 10;
          expand(shapes, size, capacity);
        }
      }
      catch (const std::runtime_error &e)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "MOVE")
    {
      point_t point;
      std::cin >> point;
      for (size_t i = 0; i < size; i++)
      {
        shapes[i]->move(point);
      }
    }
  }
  return 0;
}
