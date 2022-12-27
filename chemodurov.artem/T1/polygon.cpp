#include "polygon.hpp"
#include <stdexcept>
#include "is-repeating-points-in-array.hpp"

namespace chemodurov
{
  chemodurov::point_t * copyArrayOfPoints(const chemodurov::point_t * arr, size_t arr_size)
  {
    chemodurov::point_t * temp = new chemodurov::point_t[arr_size];
    for (size_t i = 0; i < arr_size; ++i)
    {
      temp[i] = arr[i];
    }
    return temp;
  }
  double calcPolygonArea(const chemodurov::point_t * verts, size_t num_of_verts)
  {
    double area = 0.0;
    for (size_t i = 0; i < num_of_verts; ++i)
    {
      if (i == 0)
      {
        area += verts[i].x * (verts[i + 1].y - verts[num_of_verts - 1].y);
      }
      else if (i < num_of_verts - 1)
      {
        area += verts[i].x * (verts[i + 1].y - verts[i - 1].y);
      }
      else
      {
        area += verts[i].x * (verts[0].y - verts[i - 1].y);
      }
    }
    area *= -0.5;
    return area;
  }
  chemodurov::point_t findPolygonCenter(const chemodurov::point_t * verts, size_t num_of_verts)
  {
    double area = calcPolygonArea(verts, num_of_verts);
    double x_of_center = 0.0;
    double y_of_center = 0.0;
    for (size_t i = 0; i < num_of_verts - 1; ++i)
    {
      x_of_center += (verts[i].x + verts[i + 1].x) * (verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y);
      y_of_center += (verts[i].y + verts[i + 1].y) * (verts[i].x * verts[i + 1].y - verts[i + 1].x * verts[i].y);
    }
    x_of_center /= (6 * area);
    y_of_center /= (6 * area);
    chemodurov::point_t temp{x_of_center, y_of_center};
    return temp;
  }
}

chemodurov::Polygon::Polygon(const chemodurov::point_t * verts, size_t num_of_verts):
 vertices_(chemodurov::copyArrayOfPoints(verts, num_of_verts)),
 number_of_vertices_(num_of_verts),
 center_(chemodurov::findPolygonCenter(verts, num_of_verts))
{
  if (num_of_verts < 3 || isRepeatingPointsInArray(verts, num_of_verts))
  {
    throw std::invalid_argument("Not correct vertices of polygon");
  }
}
chemodurov::Polygon::~Polygon()
{
  delete [] vertices_;
}
double chemodurov::Polygon::getArea() const
{
  return chemodurov::calcPolygonArea(vertices_, number_of_vertices_);
}
chemodurov::rectangle_t chemodurov::Polygon::getFrameRect() const
{
  double max_x = vertices_[0].x;
  double min_x = max_x;
  double max_y = vertices_[0].y;
  double min_y = max_y;
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    if (vertices_[i].x > max_x)
    {
      max_x = vertices_[i].x;
    }
    if (vertices_[i].x < min_x)
    {
      min_x = vertices_[i].x;
    }
    if (vertices_[i].y > max_y)
    {
      max_y = vertices_[i].y;
    }
    if (vertices_[i].y < min_y)
    {
      min_y = vertices_[i].y;
    }
  }
  chemodurov::point_t center{(max_x + min_x) / 2, (max_y + min_y) / 2};
  chemodurov::rectangle_t temp{center, max_x - min_x, max_y - min_y};
  return temp;
}
void chemodurov::Polygon::move(const chemodurov::point_t & pos)
{
  const point_t delta = pos - center_;
  center_ = center_ + delta;
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    vertices_[i] = vertices_[i] + delta;
  }
}
void chemodurov::Polygon::move(double dx, double dy)
{
  const point_t delta{dx, dy};
  center_ = center_ + delta;
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    vertices_[i] = vertices_[i] + delta;
  }
}
void chemodurov::Polygon::scale(double k)
{
  for (size_t i = 0; i < number_of_vertices_; ++i)
  {
    vertices_[i] = (vertices_[i] - center_) * k + center_;
  }
}
