#include "ellipse.h"
#include <cmath>
#include "base_functions.h"
namespace
{
  dimkashelk::point_t makePoint(dimkashelk::point_t center, double degree, double a, double b)
  {
    namespace dks = dimkashelk;
    double angle = degree * dks::PI / 180;
    double x = a * std::cos(angle);
    double y = b * std::sin(angle);
    dks::point_t point = dks::point_t{x, y};
    point.x += center.x;
    point.y += center.y;
    return point;
  }
  dimkashelk::point_t *makePoints(dimkashelk::point_t point, double a, double b)
  {
    if (a <= 0 || b <= 0)
    {
      throw std::logic_error("Radius must be positive");
    }
    namespace dks = dimkashelk;
    dks::point_t *points = new dks::point_t[361];
    points[0] = point;
    for (size_t degree = 0; degree < 360; degree++)
    {
      points[degree + 1] = makePoint(point, degree, a, b);
    }
    return points;
  }
  dimkashelk::Polygon makePolygon(dimkashelk::point_t point, double height, double width)
  {
    namespace dsk = dimkashelk;
    dsk::point_t *points = makePoints(point, height, width);
    dsk::Polygon polygon(points, 361);
    delete[] points;
    return polygon;
  }
}
dimkashelk::Ellipse::Ellipse(point_t point, double height, double width):
  polygon_(makePolygon(point, height, width))
{}
dimkashelk::Ellipse::Ellipse(const Polygon &polygon):
  polygon_(polygon)
{}
double dimkashelk::Ellipse::getArea() const
{
  return polygon_.getArea();
}
dimkashelk::rectangle_t dimkashelk::Ellipse::getFrameRect() const
{
  return polygon_.getFrameRect();
}
void dimkashelk::Ellipse::move(point_t point)
{
  polygon_.move(point);
}
void dimkashelk::Ellipse::move(double delta_x, double delta_y)
{
  polygon_.move(delta_x, delta_y);
}
void dimkashelk::Ellipse::unsafeScale(double k) noexcept
{
  polygon_.unsafeScale(k);
}
dimkashelk::Shape *dimkashelk::Ellipse::clone() const
{
  return new Ellipse(polygon_);
}
