#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cstddef>
#include <iomanip>
#include "rectangle.h"
#include "isotropic_scaling.h"
#include "regular.h"
#include "polygon.h"
#include "compositeshape.h"
void expand(Shape **shapes, size_t size, size_t new_capacity)
{
  if (new_capacity < size)
  {
    throw std::runtime_error("New capacity less size");
  }
  Shape **new_shapes = new Shape *[new_capacity];
  for (size_t i = 0; i < size; i++)
  {
    new_shapes[i] = shapes[i];
  }
  delete[] shapes;
  shapes = new_shapes;
}
double getArea(Shape **shapes, size_t size)
{
  double sum_area = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum_area += shapes[i]->getArea();
  }
  return sum_area;
}
std::ostream& output_shapes(std::ostream &out, Shape **shapes, size_t size)
{
  out << std::setprecision(1) << std::fixed << getArea(shapes, size);
  for (size_t i = 0; i < size; i++)
  {
    rectangle_t rect = shapes[i]->getFrameRect();
    out << " " << rect;
  }
  return out;
}
int main()
{
  std::string line = "";
  bool contains_errors_with_shapes = false;
  bool call_scale = false;
  size_t size = 0;
  size_t capacity = 10;
  Shape **shapes = new Shape*[capacity];
  while (std::cin)
  {
    std::string name = "";
    std::cin >> name;
    if (!std::cin)
    {
      break;
    }
    if (name == "RECTANGLE")
    {
      try
      {
        double x1 = 0.0;
        double y1 = 0.0;
        double x2 = 0.0;
        double y2 = 0.0;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shapes[size] = new Rectangle(point_t(x1, y1), point_t(x2, y2));
        size++;
        if (size == capacity)
        {
          capacity += 10;
          expand(shapes, size, capacity);
        }
      }
      catch (const std::logic_error &e)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "REGULAR")
    {
      try
      {
        double x = 0.0;
        double y = 0.0;
        point_t point[3];
        for (size_t i = 0; i < 3; i++)
        {
          std::cin >> x >> y;
          point[i] = point_t(x, y);
        }
        shapes[size] = new Regular(point[0], point[1], point[2]);
        size++;
        if (size == capacity)
        {
          capacity += 10;
          expand(shapes, size, capacity);
        }
      }
      catch (const std::logic_error &e)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "POLYGON")
    {
      try
      {
        size_t s = 0;
        size_t cap = 10;
        point_t *points = new point_t[cap];
        do
        {
          double x = 0.0;
          double y = 0.0;
          std::cin >> x >> y;
          if (std::cin)
          {
            points[s] = point_t(x, y);
            s++;
            if (s == cap)
            {
              cap += 10;
              point_t *new_points = new point_t[cap];
              for (size_t i = 0; i < s; i++)
              {
                new_points[i] = points[i];
              }
              delete[] points;
              points = new_points;
            }
          }
        }
        while (std::cin);
        shapes[size] = new Polygon(points, s);
        size++;
        if (size == capacity)
        {
          cap += 10;
          expand(shapes, size, capacity);
        }
        delete[] points;
      }
      catch (...)
      {
        contains_errors_with_shapes = true;
      }
      std::cin.clear();
    }
    else if (name == "COMPLEX")
    {
      try
      {
        CompositeShape compositeShape;
      }
      catch (const std::logic_error &e)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "SCALE")
    {
      call_scale = true;
      point_t point;
      std::cin >> point;
      double k = 0.0;
      std::cin >> k;
      if (k < 0)
      {
        for (size_t i = 0; i < size; i++)
        {
          delete shapes[i];
        }
        delete[] shapes;
        std::cerr << "Negative Coeff Scale";
        return 1;
      }
      if (size == 0)
      {
        delete[] shapes;
        std::cerr << "Nothing to scaling";
        return 1;
      }
      output_shapes(std::cout, shapes, size) << "\n";
      for (size_t i = 0; i < size; i++)
      {
        isotropic_scaling(shapes[i], point, k);
      }
      output_shapes(std::cout, shapes, size) << "\n";
      if (contains_errors_with_shapes)
      {
        contains_errors_with_shapes = false;
        std::cerr << "Contains errors in description of figures";
      }
    }
    else
    {
      double coord = 0.0;
      while (std::cin)
      {
        std::cin >> coord;
      }
      std::cin.clear();
    }
  }
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
  if (!call_scale)
  {
    std::cerr << "Not scaled shapes";
    return 1;
  }
  return 0;
}
