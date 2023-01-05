#include "read_correct_figures.h"

Rectangle* correctFigures::readCorrectRectangle(std::istream& in)
{
  double parameters[4] {};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[0] >= parameters[2] || parameters[1] >= parameters[3])
  { 
    throw std::logic_error("Incorrect Rectangle parameters");
  }
  return new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
}
Ring* correctFigures::readCorrectRing(std::istream& in)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  return new Ring({ parameters[0], parameters[1] }, parameters[2], parameters[3]);
}
Ellipse* correctFigures::readCorrectEllipse(std::istream& in)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  return new Ellipse({parameters[0], parameters[1]}, parameters[2], parameters[3]);
}