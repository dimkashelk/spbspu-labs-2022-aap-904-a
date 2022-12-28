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
std::ostream& output_shapes(std::ostream &out, Shape **shapes, size_t size)
{
  out << std::setprecision(1) << std::fixed;
  double sum_area = 0.0;
  for (size_t i = 0; i < size; i++)
  {
    sum_area += shapes[i]->getArea();
  }
  out << sum_area;
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
  size_t size = 0;
  size_t capacity = 10;
  Shape **shapes = new Shape*[capacity];
  while (std::cin)
  {
    std::getline(std::cin, line);
    std::istringstream in(line);
    std::string name = "";
    in >> name;
    if (name == "RECTANGLE")
    {
      try
      {
        Rectangle rect;
        in >> rect;
        shapes[size] = rect.clone();
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
        Regular regular;
        in >> regular;
        shapes[size] = regular.clone();
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
        Polygon polygon;
        in >> polygon;
        shapes[size] = polygon.clone();
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
    else if (name == "COMPLEX")
    {
      std::ostringstream data;
      size_t count = 0;
      in >> count;
      data << count << '\n';
      std::string line_of_data = "";
      for (size_t i = 0; i < count; i++)
      {
        std::getline(std::cin, line_of_data);
        data << line_of_data << '\n';
      }
      std::istringstream new_in(data.str());
      CompositeShape compositeShape;
      new_in >> compositeShape;
    }
    else if (name == "SCALE")
    {
      point_t point;
      in >> point;
      double k = 0.0;
      in >> k;
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
  }
  for (size_t i = 0; i < size; i++)
  {
    delete shapes[i];
  }
  delete[] shapes;
  return 0;
}
