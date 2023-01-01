#include <iostream>
#include <stdexcept>
#include <cstddef>
#include <iomanip>
#include "rectangle.h"
#include "isotropic_scaling.h"
#include "regular.h"
#include "polygon.h"
#include "compositeshape.h"
#include "base_functions.h"
void expand(dimkashelk::Shape **shapes, size_t size, size_t new_capacity)
{
  if (new_capacity < size)
  {
    throw std::runtime_error("New capacity less size");
  }
  dimkashelk::Shape **new_shapes = new dimkashelk::Shape*[new_capacity];
  for (size_t i = 0; i < size; i++)
  {
    new_shapes[i] = shapes[i];
  }
  delete[] shapes;
  shapes = new_shapes;
}
double getArea(dimkashelk::Shape **shapes, size_t size)
{
  double sum_area = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum_area += shapes[i]->getArea();
  }
  return sum_area;
}
std::ostream& output_shapes(std::ostream &out, dimkashelk::Shape **shapes, size_t size)
{
  out << std::setprecision(1) << std::fixed << getArea(shapes, size);
  for (size_t i = 0; i < size; i++)
  {
    dimkashelk::rectangle_t rect = shapes[i]->getFrameRect();
    dimkashelk::point_t left_down = getLeftDownPoint(rect);
    dimkashelk::point_t right_up = getRightUpPoint(rect);
    out << " " << left_down.x << " " << left_down.y << " " << right_up.x << " " << right_up.y;
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
  dimkashelk::Shape **shapes = new dimkashelk::Shape*[capacity];
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
        shapes[size] = new dimkashelk::Rectangle(dimkashelk::point_t{x1, y1}, dimkashelk::point_t{x2, y2});
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
        dimkashelk::point_t point[3];
        for (size_t i = 0; i < 3; i++)
        {
          std::cin >> x >> y;
          point[i] = dimkashelk::point_t{x, y};
        }
        shapes[size] = new dimkashelk::Regular(point[0], point[1], point[2]);
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
      dimkashelk::point_t *points = nullptr;
      try
      {
        size_t s = 0;
        size_t cap = 10;
        points = new dimkashelk::point_t[cap];
        do
        {
          double x = 0.0;
          double y = 0.0;
          std::cin >> x >> y;
          if (std::cin)
          {
            points[s] = dimkashelk::point_t{x, y};
            s++;
            if (s == cap)
            {
              cap += 10;
              dimkashelk::point_t *new_points = new dimkashelk::point_t[cap];
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
        shapes[size] = new dimkashelk::Polygon(points, s);
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
        delete[] points;
        contains_errors_with_shapes = true;
      }
      std::cin.clear();
    }
    else if (name == "COMPLEX")
    {
      try
      {
        dimkashelk::CompositeShape compositeShape;
      }
      catch (const std::logic_error &e)
      {
        contains_errors_with_shapes = true;
      }
    }
    else if (name == "SCALE")
    {
      call_scale = true;
      double x = 0.0;
      double y = 0.0;
      std::cin >> x >> y;
      dimkashelk::point_t point{x, y};
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
