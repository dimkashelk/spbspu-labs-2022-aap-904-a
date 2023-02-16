#include "createPoints.h"

double *createCoordinates(std::istream& in, std::size_t size)
{
  double *coordinates = new double[size];
  for (std::size_t i = 0; i < size; ++i)
  {
    in >> coordinates[i];
    if (!in)
    {
      throw std::invalid_argument("error input");
    }
  }
  return coordinates;
}

point_t *fillPoints(double *coordinates, std::size_t size)
{
  point_t *points = new point_t[size];
  for (std::size_t i = 0; i < size; i++)
  {
    if (i == 0)
    {
      points[i].x = coordinates[0];
      points[i].y = coordinates[1];
    }
    else if (i == 1)
    {
      points[i].x = coordinates[2];
      points[i].y = coordinates[3];
    }
    else if (i == 2)
    {
      points[i].x = coordinates[4];
      points[i].y = coordinates[5];
    }
  }
  return points;
}
