#include "GetShapes.hpp"
#include "Rectangle.hpp"
#include "Ellipse.hpp"

Shape *makeRectangle(std::istream &input)
{
  double p[4]{0.0, 0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2] >> p[3];
  return new Rectangle({p[0], p[1]}, {p[2], p[3]});
}

Shape *makeEllipse(std::istream &input)
{
  double p[4]{0.0, 0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2] >> p[3];
  return new Ellipse({p[0], p[1]}, p[3], p[2]);
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
