#include "rectangle.h"
#include <cmath>
#include <stdexcept>

Rectangle::Rectangle(point_t left_down, point_t right_up):
  left_down_(left_down),
  right_up_(right_up),
  left_up_ {left_down.x, right_up.y}
{}

rectangle_t Rectangle::getFrameRectangle() const
{
  rectangle_t frame_rectangle{};
  frame_rectangle.height = left_up_.y - left_down_.y;
  frame_rectangle.width = right_up_.x - left_up_.x;
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
  left_down_.x += dx;
  left_down_.y += dy;
  left_up_.x += dx;
  left_up_.y += dy;
  right_up_.x += dx;
  right_up_.y += dy;
}

void Rectangle::move(point_t position)
{
  double dx = position.x - getFrameRectangle().position.x;
  double dy = position.y - getFrameRectangle().position.y;
  move(dx, dy);
}

void Rectangle::scale(double k)
{
  double center_x = getFrameRectangle().position.x;
  double center_y = getFrameRectangle().position.y;
  left_down_.x = center_x + (left_down_.x - center_x) * k;
  left_down_.y = center_y + (left_down_.y - center_y) * k;
  right_up_.x = center_x + (right_up_.x - center_x) * k;
  right_up_.y = center_y + (right_up_.y - center_y) * k;
  left_up_.x = left_down_.x;
  left_up_.y = right_up_.y;
}
