#include "GetShapes.hpp"
#include "Rectangle.hpp"
#include "Ellipse.hpp"
#include "Concave.hpp"

Shape *makeRectangle(std::istream &input)
{
  double dot[4]{0.0, 0.0, 0.0, 0.0};
  input >> dot[0] >> dot[1] >> dot[2] >> dot[3];
  return new Rectangle({dot[0], dot[1]}, {dot[2], dot[3]});
}

Shape *makeEllipse(std::istream &input)
{
  double dot[4]{0.0, 0.0, 0.0, 0.0};
  input >> dot[0] >> dot[1] >> dot[2] >> dot[3];
  return new Ellipse({dot[0], dot[1]}, dot[3], dot[2]);
}

Shape *makeConcave(std::istream &input)
{
  double dot[8]{0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  input >> dot[0] >> dot[1] >> dot[2] >> dot[3];
  return new Concave({dot[0], dot[1]}, {dot[2], dot[3]}, {dot[4], dot[5]}, {dot[6], dot[7]});
}

scale_t calcScale(std::istream &input)
{
  double p[3]{0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2];
  if (p[2] < 0.0)
  {
    throw std::invalid_argument("bad scale size");
  }
  return {{p[0], p[1]}, p[2]};
}
