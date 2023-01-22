#include "ellipse.h"
#include <cmath>
#include "base_functions.h"
#include "make_triangles.h"
dimkashelk::Ellipse::Ellipse(point_t point, double height, double width):
  triangles(makeTriangles(point, height, width))
{}
dimkashelk::point_t makePoint(dimkashelk::point_t center, double degree, double a, double b)
{
  double angle = degree * dimkashelk::PI / 180;
  double x = (a * b) / std::sqrt(b * b + a * a * std::tan(angle));
  if (degree >= 90 && degree <= 270)
  {
    x *= -1;
  }
  double y = std::sqrt(1 - (x / a) * (x / a)) * b;
  if (degree >= 90 && degree <= 270)
  {
    y *= -1;
  }
  dimkashelk::point_t point = dimkashelk::point_t{x, y};
  point.x += center.x;
  point.y += center.y;
  return point;
}
dimkashelk::Triangle *dimkashelk::makeTriangles(point_t point, double a, double b)
{
  point_t *points = new point_t[361];
  points[0] = point;
  for (int degree = 0; degree < 360; degree++)
  {
    points[degree + 1] = makePoint(point, degree, a, b);
  }
  TriangulatePoints triangulatePoints(points, 361);
  Triangle *triangles = new Triangle[359];
  size_t i = 0;
  while (triangulatePoints.hasNext())
  {
    triangles[i] = triangulatePoints();
  }
  return triangles;
}
double dimkashelk::Ellipse::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < 359; i++)
  {
    area += triangles[i].getArea();
  }
  return area;
}
dimkashelk::rectangle_t dimkashelk::Ellipse::getFrameRect() const
{
  rectangle_t frame_0_degree = triangles[0].getFrameRect();
  rectangle_t frame_90_degree = triangles[89].getFrameRect();
  rectangle_t frame_180_degree = triangles[179].getFrameRect();
  rectangle_t frame_270_degree = triangles[269].getFrameRect();
  return dimkashelk::getFrameRect(
    dimkashelk::getFrameRect(frame_0_degree, frame_90_degree),
    dimkashelk::getFrameRect(frame_180_degree, frame_270_degree));
}
