#include "make_output.h"
#include <iomanip>
#include <iostream>
#include "shape.h"

void makeOutputPosition(std::ostream& out, Shape* figure)
{
  out << std::fixed;
  auto round = std::setprecision(1);
  rectangle_t frame_rectangle = figure->getFrameRectangle();
  double framed_x1 = frame_rectangle.position.x - frame_rectangle.width / 2;
  double framed_y1 = frame_rectangle.position.y - frame_rectangle.height / 2;
  double framed_x2 = frame_rectangle.position.x + frame_rectangle.width / 2;
  double framed_y2 = frame_rectangle.position.y + frame_rectangle.height / 2;
  out << " " << round << framed_x1 << " " << round << framed_y1 << " ";
  out << round << framed_x2 << " " << round << framed_y2;
}

void makeOutput(std::ostream& out, Shape** array_figures, size_t size)
{
  if (!size)
  {
    throw std::invalid_argument("Invalid size of Shape array");
  }
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum += array_figures[i]->getArea();
  }
  out << std::fixed << std::setprecision(1) << sum;
  for (size_t i = 0; i < size; i++)
  {
    makeOutputPosition(out, array_figures[i]);
  }
  out << "\n";
}

