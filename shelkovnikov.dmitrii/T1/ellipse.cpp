#include "ellipse.h"
#include <cmath>
#include "base_functions.h"
namespace
{
  dimkashelk::point_t makePoint(dimkashelk::point_t center, double degree, double a, double b)
  {
    double angle = degree * dimkashelk::PI / 180;
    double x = (a * b) / std::sqrt(b * b + a * a * std::tan(angle));
    if (degree >= 90 && degree <= 270)
    {
      x *= -1;
    }
    double y = std::sqrt(1 - (x / a) * (x / a)) * b;
    if (degree >= 180 && degree <= 360)
    {
      y *= -1;
    }
    dimkashelk::point_t point = dimkashelk::point_t{x, y};
    point.x += center.x;
    point.y += center.y;
    return point;
  }
  dimkashelk::point_t *makePoints(dimkashelk::point_t point, double a, double b)
  {
    dimkashelk::point_t *points = new dimkashelk::point_t[361];
    points[0] = point;
    for (int degree = 0; degree < 360; degree++)
    {
      points[degree + 1] = makePoint(point, degree, a, b);
    }
    return points;
  }
}
dimkashelk::Ellipse::Ellipse(point_t point, double height, double width):
  polygon(makePoints(point, height, width), 361)
{}
dimkashelk::Ellipse::Ellipse(const Polygon &polygon):
  polygon(polygon)
{}
double dimkashelk::Ellipse::getArea() const
{
  return polygon.getArea();
}
dimkashelk::rectangle_t dimkashelk::Ellipse::getFrameRect() const
{
  return polygon.getFrameRect();
}
void dimkashelk::Ellipse::move(point_t point)
{
  polygon.move(point);
}
void dimkashelk::Ellipse::move(double delta_x, double delta_y)
{
  polygon.move(delta_x, delta_y);
}
void dimkashelk::Ellipse::scale(double k)
{
  polygon.scale(k);
}
void dimkashelk::Ellipse::unsafeScale(double k) noexcept
{
  polygon.unsafeScale(k);
}
dimkashelk::Shape *dimkashelk::Ellipse::clone() const
{
  return new Ellipse(polygon);
}
