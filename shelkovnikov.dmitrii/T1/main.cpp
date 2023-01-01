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
#include "input_shapes.h"
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
    dimkashelk::point_t left_down = get_left_down_point(rect);
    dimkashelk::point_t right_up = get_right_up_point(rect);
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
        shapes[size] = dimkashelk::input_rectangle(std::cin);
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
        shapes[size] = dimkashelk::input_regular(std::cin);
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
        shapes[size] = dimkashelk::input_polygon(std::cin);
        size++;
        if (size == capacity)
        {
          capacity += 10;
          expand(shapes, size, capacity);
        }
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
        dimkashelk::CompositeShape compositeShape = *dimkashelk::input_composite_shape(std::cin);
      }
      catch (...)
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
        dimkashelk::isotropic_scaling(shapes[i], point, k);
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
