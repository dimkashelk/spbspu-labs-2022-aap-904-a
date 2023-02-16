#include "createPoints.h"

double* createCoordinates(std::istream& in, std::size_t size)
{
  double *coordinates = new double[size];
  for (int i = 0; i < size; ++i)
  {
    in >> coordinates[i];
    if (!in)
    {
      throw std::invalid_argument("error input");
    }
  }
  return coordinates;
}

point_t* fillPoints(double *coordinates, std::size_t size)
{
  point_t *points = new point_t[size];
  for (std::size_t i = 0; i < size; i++)
  {
    for (int j = 0; j < size * 2; j+=2)
    {
      points[i].x = coordinates[j];
      points[i].y = coordinates[j+1];
      break;
    }
  }
}
