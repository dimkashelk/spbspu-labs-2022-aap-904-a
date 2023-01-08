#include "shape.h"
#include <typeinfo>
#include <cmath>
#include "rectangle.h"
#include "square.h"
#include "circle.h"

namespace kryuchkova
{
  void isoScale(kryuchkova::Shape *shape, point_t point, double k)
  {
    if (k <= 0)
    {
      throw std::invalid_argument("scaling koef must be positive");
    }
    rectangle_t rect1 = shape->getFrameRect();
    point_t pos1 = rect1.pos;
    shape->move(point);
    rectangle_t rect2 = shape->getFrameRect();
    point_t pos2 = rect2.pos;
    double dx = k * (pos1.x - pos2.x);
    double dy = k * (pos1.y - pos2.y);
    shape->scale(k);
    shape->move(dx, dy);
  }

  std::ostream& operator<<(std::ostream &out, const point_t &point)
  {
    return out << point.x << " " << point.y;
  }

  std::ostream& operator<<(std::ostream &out, const Shape &shape)
  {
    std::string name = shape.getName();
    double area = shape.getArea();
    kryuchkova::rectangle_t rect = shape.getFrameRect();
    kryuchkova::point_t lb(rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2);
    kryuchkova::point_t ru(rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2);
    return out << name << " " << area << " " << lb << ' ' << ru;
  }

  bool Shape::operator<(const Shape &sh)
  {
    return (getArea() < sh.getArea());
  }

  Shape *inputRectangle(std::istream &in)
  {
    double lb_x = 0.0;
    double lb_y = 0.0;
    double ru_x = 0.0;
    double ru_y = 0.0;
    in >> lb_x >> lb_y >> ru_x >> ru_y;
    if (!in)
    {
      throw std::invalid_argument("invalid input");
    }
    return new Rectangle(point_t(lb_x, lb_y), point_t(ru_x, ru_y));
  }

  Shape *inputCircle(std::istream &in)
  {
    double pos_x = 0.0;
    double pos_y = 0.0;
    double radius = 0.0;
    in >> pos_x >> pos_y >> radius;
    if (!in)
    {
      throw std::invalid_argument("invalid input");
    }
    return new Circle(point_t(pos_x, pos_y), radius);
  }

  Shape *inputSquare(std::istream &in)
  {
    double lb_x = 0.0;
    double lb_y = 0.0;
    double length = 0.0;
    in >> lb_x >> lb_y >> length;
    if (!in)
    {
      throw std::invalid_argument("invalid input");
    }
    return new Square(point_t(lb_x, lb_y), length);
  }
}
