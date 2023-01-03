#include "readWriteShapes.h"
#include <istream>
#include <iomanip>
#include "shapesPatterns.h"

turkin::Rectangle * turkin::createRectangle(std::istream & input)
{
  double points[4] {0.0, 0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2] >> points[3];
  if (points[0] > points[2] || points[1] > points[3])
  {
    throw std::logic_error("bad rectangle size");
  }
  return new turkin::Rectangle(turkin::point_t(points[0], points[1]), turkin::point_t(points[2], points[3]));
}

turkin::Rectangle * turkin::createSquare(std::istream & input)
{
  double points[3] {0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2];
  if (points[2] <= 0.0)
  {
    throw std::logic_error("bad square size");
  }
  return new turkin::Rectangle(turkin::point_t(points[0], points[1]), points[2]);
}

turkin::Ellipse * turkin::createEllipse(std::istream & input)
{
  double points[4] {0.0, 0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2] >> points[3];
  if (points[2] <= 0.0 || points[3] <= 0.0)
  {
    throw std::logic_error("bad ellipse size");
  }
  return new turkin::Ellipse(turkin::point_t(points[0], points[1]), points[2], points[3]);
}

turkin::scale_t turkin::getScale(std::istream &input)
{
  double points[3] {0.0, 0.0, 0.0};
  input >> points[0] >> points[1] >> points[2];
  if (points[2] < 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  return {turkin::point_t(points[0], points[1]), points[2]};
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
    turkin::rectangle_t buffer = shapes[i]->getFrameRect();
    output << " " << buffer.position.x - (buffer.width / 2.0) << " ";
    output << buffer.position.y - (buffer.height / 2.0) << " ";
    output << buffer.position.x + (buffer.width / 2.0) << " ";
    output << buffer.position.y + (buffer.height / 2.0);
  }
  output << "\n";
}

