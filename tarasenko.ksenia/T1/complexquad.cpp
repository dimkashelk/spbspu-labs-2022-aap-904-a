#include "complexquad.hpp"
#include "triangle.hpp"
#include <stdexcept>

tarasenko::Complexquad::Complexquad(point_t point_1, point_t point_2, point_t point_3, point_t point_4):
  vertexes{point_1, point_2, point_3, point_4},
  p_cross(0, 0)
{
  double a1 = point_2.y_ - point_1.y_;
  double b1 = point_1.x_ - point_2.x_;
  double c1 = -point_1.x_ * point_2.y_ + point_1.y_ * point_2.x_;
  double a2 = point_4.y_ - point_3.y_;
  double b2 = point_3.x_ - point_4.x_;
  double c2 = -point_3.x_ * point_4.y_ + point_3.y_ * point_4.x_;
  if ((a1 * b2 - a2 * b1) == 0 || (a1 * b2 == b1 * a2 && a1 * c2 == a2 * c1 && b1 * c2 == c1 * b2))
  {
    throw std::invalid_argument("incorrect complexquad coordinates");
  }
  p_cross.x_ = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
  p_cross.y_ = (a2 * c1 - a1 * c2) / (a1 * b2 - a2 * b1);
}

double tarasenko::Complexquad::getArea() const
{
  tarasenko::Triangle triangle_1(vertexes[0], vertexes[3], p_cross);
  tarasenko::Triangle triangle_2(vertexes[1], vertexes[2], p_cross);
  return triangle_1.getArea() + triangle_2.getArea();
}

tarasenko::rectangle_t tarasenko::Complexquad::getFrameRect() const
{
  double min_x = std::min(std::min(vertexes[0].x_, vertexes[1].x_), std::min(vertexes[2].x_, vertexes[3].x_));
  double min_y = std::min(std::min(vertexes[0].y_, vertexes[1].y_), std::min(vertexes[2].y_, vertexes[3].y_));
  double max_x = std::max(std::max(vertexes[0].x_, vertexes[1].x_), std::max(vertexes[2].x_, vertexes[3].x_));
  double max_y = std::max(std::max(vertexes[0].y_, vertexes[1].y_), std::max(vertexes[2].y_, vertexes[3].y_));
  rectangle_t frame_rect(point_t(min_x, min_y),point_t(max_x, max_y));
  return frame_rect;
}

void tarasenko::Complexquad::move(double dx, double dy)
{
  for (int i = 0; i < 4; i++)
  {
    vertexes[i].x_ += dx;
    vertexes[i].y_ += dy;
  }
  p_cross.x_ += dx;
  p_cross.y_ += dy;
}

void tarasenko::Complexquad::move(point_t pos)
{
  this->move(pos.x_ - p_cross.x_, pos.y_ - p_cross.y_);
}

void tarasenko::Complexquad::scale(double k)
{
  this->checkCoefficient(k);
  for (int i = 0; i < 4; i++)
  {
    vertexes[i].x_ = p_cross.x_ + (vertexes[i].x_ - p_cross.x_) * k;
    vertexes[i].y_ = p_cross.y_ + (vertexes[i].y_ - p_cross.y_) * k;
  }
}

tarasenko::Shape * tarasenko::Complexquad::clone() const
{
  return new Complexquad(vertexes[0], vertexes[1], vertexes[2], vertexes[3]);
}
