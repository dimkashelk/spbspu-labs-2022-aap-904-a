#include "PrintCoordinates.hpp"
#include <iomanip>

void printAreaPoints(std::ostream &out, Shape **shapes, size_t size)
{
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  out << std::setprecision(1) << std::fixed << sum;
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t temp_shape = shapes[i]->getFrameRect();
    out << " " << temp_shape.pos.x - (temp_shape.width / 2.0) << " ";
    out << temp_shape.pos.y - (temp_shape.height / 2.0) << " ";
    out << temp_shape.pos.x + (temp_shape.width / 2.0) << " ";
    out << temp_shape.pos.y + (temp_shape.height / 2.0);
  }
  out << "\n";
}