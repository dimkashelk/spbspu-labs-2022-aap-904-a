#include "shape.h"
#include <typeinfo>

namespace kryuchkova
{
  void isoScale(kryuchkova::Shape *shape, point_t point, double k)
  {
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

  std::ostream& operator << (std::ostream &out, const point_t &point)
  {
    return out << point.x << " " << point.y;
  }

  std::ostream& operator << (std::ostream &out, const Shape &shape)
  {
    std::setprecision(1);
    std::string name = typeid(shape).name();
    double area = shape.getArea();
    kryuchkova::rectangle_t rect = shape.getFrameRect();
    kryuchkova::point_t lb(rect.pos.x - rect.width / 2, rect.pos.y - rect.height / 2);
    kryuchkova::point_t ru(rect.pos.x + rect.width / 2, rect.pos.y + rect.height / 2); 
    return out << name << " " << area << " " << lb << ru << '\n';
  }
}
