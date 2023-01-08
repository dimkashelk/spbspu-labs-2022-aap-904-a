#include "read_correct_figures.h"
#include "ellipse.h"
#include "rectangle.h"
#include "ring.h"

Shape* correctFigures::readCorrectRectangle(std::istream& in)
{
  double parameters[4] {};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[0] >= parameters[2] || parameters[1] >= parameters[3])
  {
    throw std::invalid_argument("Error: false rectangle parameters");
  }
  return new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
}

Shape* correctFigures::readCorrectRing(std::istream& in)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[2] <= parameters[3] || parameters[2] <= 0 || parameters[3] <= 0)
  {
    throw std::invalid_argument("Error: false ring parameters");
  }
  return new Ring({ parameters[0], parameters[1] }, parameters[3], parameters[2]);
}

Shape* correctFigures::readCorrectEllipse(std::istream& in)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[2] <= 0 || parameters[3] <= 0)
  {
    throw std::invalid_argument("Error: false ellipse parameters");
  }
  return new Ellipse({parameters[0], parameters[1]}, parameters[2], parameters[3]);
}
