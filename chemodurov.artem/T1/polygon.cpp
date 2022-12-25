#include "polygon.hpp"

chemodurov::Polygon::Polygon(const chemodurov::point_t * vertices, size_t number_of_vertices)
{
  chemodurov::point_t * temp = new point_t[number_of_vertices];
  for (size_t i = 0; i < number_of_vertices; ++i)
  {
    temp[i] = vertices[i];
  }
  vertices_ = temp;
  number_of_vertices_ = number_of_vertices;
  chemodurov::point_t center{0, 0};
  center_ = center;
}
