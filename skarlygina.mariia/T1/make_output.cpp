#include "make_output.h"
#include <iomanip>
#include <iostream>
#include "shape.h"

void makeOutputPosition(std::ostream& out, Shape* figure)
{
  out << std::fixed;
  rectangle_t frame_rectangle = figure->getFrameRectangle();
  double framed_x1 = frame_rectangle.position.x - frame_rectangle.width / 2;
  double framed_y1 = frame_rectangle.position.y - frame_rectangle.height / 2;
  double framed_x2 = frame_rectangle.position.x + frame_rectangle.width / 2;
  double framed_y2 = frame_rectangle.position.y + frame_rectangle.height / 2;
  out << framed_x1 << " " << framed_y1 << " ";
  out << framed_x2 << " " << framed_y2;
}
