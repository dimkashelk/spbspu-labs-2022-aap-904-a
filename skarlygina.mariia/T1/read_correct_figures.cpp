#include "read_correct_figures.h"

Shape* correctFigures::readCorrectRectangle(std::istream& in)
{
  double parameters[4] {};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[0] >= parameters[2] || parameters[1] >= parameters[3])
  {
    return nullptr;
  }
  return new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
}

Shape* correctFigures::readCorrectRing(std::istream& in)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[2] <= parameters[3] || parameters[2] <= 0 || parameters[3] <= 0)
  {
    return nullptr;
  }
  return new Ring({ parameters[0], parameters[1] }, parameters[3], parameters[2]);
}

Shape* correctFigures::readCorrectEllipse(std::istream& in)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[2] <= 0 || parameters[3] <= 0)
  {
    return nullptr;
  }
  return new Ellipse({parameters[0], parameters[1]}, parameters[2], parameters[3]);
}
