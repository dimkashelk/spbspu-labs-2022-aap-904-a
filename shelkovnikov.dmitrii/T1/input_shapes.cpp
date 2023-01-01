#include "input_shapes.h"
#include <stdexcept>
dimkashelk::Rectangle* dimkashelk::input_rectangle(std::istream &in)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  if (!in)
  {
    throw std::logic_error("Not enough data for input");
  }
  return new Rectangle(point_t{x1, y1}, point_t{x2, y2});
}
dimkashelk::Regular *dimkashelk::input_regular(std::istream &in)
{
  double x = 0.0;
  double y = 0.0;
  dimkashelk::point_t point[3];
  for (size_t i = 0; i < 3; i++)
  {
    in >> x >> y;
    point[i] = dimkashelk::point_t{x, y};
  }
  if (!in)
  {
    throw std::logic_error("Not enough data for input");
  }
  return new Regular(point[0], point[1], point[2]);
}
dimkashelk::Polygon *dimkashelk::input_polygon(std::istream &in)
{
  size_t s = 0;
  size_t cap = 10;
  point_t *points = new dimkashelk::point_t[cap];
  do
  {
    double x = 0.0;
    double y = 0.0;
    in >> x >> y;
    if (in)
    {
      points[s] = dimkashelk::point_t{x, y};
      s++;
      if (s == cap)
      {
        cap += 10;
        dimkashelk::point_t *new_points = new dimkashelk::point_t[cap];
        for (size_t i = 0; i < s; i++)
        {
          new_points[i] = points[i];
        }
        delete[] points;
        points = new_points;
      }
    }
  }
  while (in);
  Polygon *polygon = new Polygon(points, s);
  delete[] points;
  return polygon;
}
