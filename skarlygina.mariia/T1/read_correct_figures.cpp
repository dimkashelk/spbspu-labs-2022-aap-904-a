#include "read_correct_figures.h"

Rectangle* correctFigures::readCorrectRectangle(std::istream& in, bool& isCorrect)
{
  double parameters[4] {};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[0] >= parameters[2] || parameters[1] >= parameters[3])
  {
    isCorrect = false;
  }
  return new Rectangle({parameters[0], parameters[1]}, {parameters[2], parameters[3]});
}

Ring* correctFigures::readCorrectRing(std::istream& in, bool& isCorrect)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[2] <= parameters[3] || parameters[2] <= 0 || parameters[3] <= 0)
  {
    isCorrect = false;
  }
  return new Ring({ parameters[0], parameters[1] }, parameters[3], parameters[2]);
}

Ellipse* correctFigures::readCorrectEllipse(std::istream& in, bool& isCorrect)
{
  double parameters[4]{};
  in >> parameters[0] >> parameters[1] >> parameters[2] >> parameters[3];
  if (parameters[2] <= 0 || parameters[3] <= 0)
  {
    isCorrect = false;
  }
  return new Ellipse({parameters[0], parameters[1]}, parameters[2], parameters[3]);
}
