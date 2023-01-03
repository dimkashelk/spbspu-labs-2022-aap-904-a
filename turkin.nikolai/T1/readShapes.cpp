#include "readShapes.h"
#include <istream>
#include "shapesPatterns.h"

turkin::Rectangle * turkin::createRectangle(std::istream & input)
{
  double points[4] {0.0, 0.0, 0.0, 0.0};
  std::string buffer;
  for (double & i : points)
  {
    input >> buffer;
    i = std::stod(buffer);
  }
  if (points[0] > points[2] || points[1] > points[3])
  {
    throw std::logic_error("bad rectangle size");
  }
  return new turkin::Rectangle(turkin::point_t(points[0], points[1]), turkin::point_t(points[2], points[3]));
}

turkin::Rectangle * turkin::createSquare(std::istream & input)
{
  double points[3] {0.0, 0.0, 0.0};
  std::string buffer;
  for (double & i : points)
  {
    input >> buffer;
    i = std::stod(buffer);
  }
  if (points[2] <= 0.0)
  {
    throw std::logic_error("bad square size");
  }
  return new turkin::Rectangle(turkin::point_t(points[0], points[1]), points[2]);
}

turkin::Ellipse * turkin::createEllipse(std::istream & input)
{
  double points[4] {0.0, 0.0, 0.0, 0.0};
  std::string buffer;
  for (double & i : points)
  {
    input >> buffer;
    i = std::stod(buffer);
  }
  if (points[2] <= 0.0 || points[3] <= 0.0)
  {
    throw std::logic_error("bad ellipse size");
  }
  return new turkin::Ellipse(turkin::point_t(points[0], points[1]), points[2], points[3]);
}

turkin::scale_t turkin::getScale(std::istream &input)
{
  double points[3] {0.0, 0.0, 0.0};
  std::string buffer;
  for (double & i : points)
  {
    input >> buffer;
    i = std::stod(buffer);
  }
  if (points[2] < 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  return {turkin::point_t(points[0], points[1]), points[2]};
}

