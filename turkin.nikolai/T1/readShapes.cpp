#include "readShapes.h"
#include "shapesPatterns.h"
#include <iostream>

turkin::Rectangle * turkin::createRectangle(std::istream & input)
{
  double points[4] {0.0, 0.0, 0.0, 0.0};
  std::string buffer;
  for (double & i : points)
  {
    input >> buffer;
    i = std::stod(buffer);
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
  return {turkin::point_t(points[0], points[1]), points[2]};
}
