#include "rectangle.h"
#include "base_types.h"
#include <cmath>
#include <stdexcept>

Rectangle::Rectangle(point_t left_down, point_t right_up):
  left_down_(left_down),
  right_up_(right_up)
{}

rectangle_t Rectangle::getFrameRectangle() const
{
  rectangle_t frame_rectangle{};
  frame_rectangle.height = right_up_.y - left_down_.y;
  frame_rectangle.width = right_up_.x - left_down_.x;
  frame_rectangle.position.x = (left_down_.x + right_up_.x) / 2;
  frame_rectangle.position.y = (left_down_.y + right_up_.y) / 2;
  return frame_rectangle;
}

double Rectangle::getArea() const
{
  double area_rectangle = getFrameRectangle().width * getFrameRectangle().height;
  return area_rectangle;
}

void Rectangle::move(double dx, double dy)
{
  left_down_ = baseFunctions::SummVector(left_down_, dx, dy);
  right_up_ = baseFunctions::SummVector(right_up_, dx, dy);
}

void Rectangle::move(point_t position)
{
  point_t diff = baseFunctions::findDifference(position, getFrameRectangle().position);
  move(diff.x, diff.y);
}

void Rectangle::scale(double k)
{
  left_down_ = baseFunctions::Scale(left_down_, getFrameRectangle().position, k);
  right_up_ = baseFunctions::Scale(right_up_, getFrameRectangle().position, k);
}
