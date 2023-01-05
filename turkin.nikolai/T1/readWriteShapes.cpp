#include "readWriteShapes.h"
#include <istream>
#include <iomanip>

turkin::Rectangle * turkin::createRectangle(std::istream & input)
{
  double points[4] {0.0, 0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2] >> points[3];
  if (points[0] > points[2] || points[1] > points[3])
  {
    throw std::logic_error("bad rectangle size");
  }
  return new Rectangle({points[0], points[1]}, {points[2], points[3]});
}

turkin::Rectangle * turkin::createSquare(std::istream & input)
{
  double points[3] {0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2];
  if (points[2] <= 0.0)
  {
    throw std::logic_error("bad square size");
  }
  return new Rectangle({points[0] - points[2] / 2.0, points[1] - points[2] / 2.0}, {points[0] + points[2] / 2.0, points[1] + points[2] / 2.0});
}

turkin::Ellipse * turkin::createEllipse(std::istream & input)
{
  double points[4] {0.0, 0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2] >> points[3];
  if (points[2] <= 0.0 || points[3] <= 0.0)
  {
    throw std::logic_error("bad ellipse size");
  }
  return new Ellipse({points[0], points[1]}, points[2] * 2.0, points[3] * 2.0);
}

turkin::scale_t turkin::getScale(std::istream &input)
{
  double points[3] {0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2];
  if (points[2] < 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  return {{points[0], points[1]}, points[2]};
}

void turkin::printAreaPoints(std::ostream & output, Shape ** shapes, size_t size)
{
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  output << std::setprecision(1) << std::fixed << sum;
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t buffer = shapes[i]->getFrameRect();
    output << " " << buffer.position.x - (buffer.width / 2.0) << " ";
    output << buffer.position.y - (buffer.height / 2.0) << " ";
    output << buffer.position.x + (buffer.width / 2.0) << " ";
    output << buffer.position.y + (buffer.height / 2.0);
  }
  output << "\n";
}

