#include "triangle.h"
#include <cmath>
#include <stdexcept>
Triangle::Triangle(point_t p1, point_t p2, point_t p3):
  point1(p1),
  point2(p2),
  point3(p3)
{
  double side1 = sqrt(pow((point1.x - point2.x), 2) + pow(point1.y - point2.y, 2));
  double side2 = sqrt(pow((point1.x - point3.x), 2) + pow(point1.y - point3.y, 2));
  double side3 = sqrt(pow((point3.x - point2.x), 2) + pow(point3.y - point2.y, 2));
  if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2)
  {
    throw std::logic_error("It's not a triangle");
  }
}
Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3):
  Triangle(point_t(x1, y1), point_t(x2, y2), point_t(x3, y3))
{}
