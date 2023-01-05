#include "readWriteShapes.h"
#include <istream>
#include <iomanip>

turkin::Rectangle * turkin::createRectangle(std::istream & input)
{
  double p[4] {0.0, 0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2] >> p[3];
  if (p[0] > p[2] || p[1] > p[3])
  {
    throw std::logic_error("bad rectangle size");
  }
  return new Rectangle({p[0], p[1]}, {p[2], p[3]});
}

turkin::Rectangle * turkin::createSquare(std::istream & input)
{
  double p[3] {0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2];
  if (p[2] <= 0.0)
  {
    throw std::logic_error("bad square size");
  }
  return new Rectangle({p[0], p[1]}, {p[0] + p[2], p[1] + p[2]});
}

turkin::Ellipse * turkin::createEllipse(std::istream & input)
{
  double p[4] {0.0, 0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2] >> p[3];
  if (p[2] <= 0.0 || p[3] <= 0.0)
  {
    throw std::logic_error("bad ellipse size");
  }
  return new Ellipse({p[0], p[1]}, p[3], p[2]);
}

turkin::scale_t turkin::getScale(std::istream &input)
{
  double p[3] {0.0, 0.0, 0.0};
  input >> p[0] >> p[1] >> p[2];
  if (p[2] < 0.0)
  {
    throw std::logic_error("bad scale size");
  }
  return {{p[0], p[1]}, p[2]};
}

void turkin::printAreaPoints(std::ostream & output, Shape ** shapes, size_t size)
{
  double sum = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum = sum + shapes[i]->getArea();
  }
  output << std::setprecision(1) << std::fixed << sum;
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t buffer = shapes[i]->getFrameRect();
    output << " " << buffer.position.x - (buffer.width / 2.0) << " ";
    output << buffer.position.y - (buffer.height / 2.0) << " ";
    output << buffer.position.x + (buffer.width / 2.0) << " ";
    output << buffer.position.y + (buffer.height / 2.0);
  }
  output << "\n";
}

