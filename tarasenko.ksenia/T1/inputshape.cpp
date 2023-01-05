#include "inputshape.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "complexquad.hpp"

tarasenko::Shape * inputRectangle(std::istream & input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  input >> x1 >> y1 >> x2 >> y2;
  if (!input)
  {
    throw std::invalid_argument("error in coordinates");
  }
  tarasenko::point_t point_ld(x1,y1);
  tarasenko::point_t point_ru(x2,y2);
  return new tarasenko::Rectangle(point_ld, point_ru);
}

tarasenko::Shape * inputTriangle(std::istream & input)
{
  double x = 0.0;
  double y = 0.0;
  tarasenko::point_t point(x, y);
  tarasenko::point_t vertexes[3] = {point, point, point};
  for (int i = 0; i < 3; i++)
  {
    input >> x >> y;
    if (!std::cin)
    {
      throw std::invalid_argument("error in coordinates");
    }
    vertexes[i] = tarasenko::point_t(x, y);
  }
  return new tarasenko::Triangle(vertexes[0], vertexes[1], vertexes[2]);
}

tarasenko::Shape * inputComplexquad(std::istream & input)
{
  double x = 0.0;
  double y = 0.0;
  tarasenko::point_t point(x, y);
  tarasenko::point_t vertexes[4] = {point, point, point, point};
  for (int i = 0; i < 4; i++)
  {
    input >> x >> y;
    if (!std::cin)
    {
      throw std::invalid_argument("error in coordinates");
    }
    vertexes[i] = tarasenko::point_t(x, y);
  }
  return new tarasenko::Complexquad(vertexes[0], vertexes[1], vertexes[2], vertexes[3]);
}