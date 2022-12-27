#ifndef SPBSPU_LABS_2022_AAP_904_A_COMPOSITE_SHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_COMPOSITE_SHAPE_H
#include <cstddef>
#include <sstream>
#include "base_types.h"
#include "shape.h"
#include "rectangle.h"
#include "regular.h"
#include "polygon.h"
class CompositeShape
{
public:
  CompositeShape();
  CompositeShape(Shape **shapes, size_t size);
  CompositeShape(const CompositeShape &compositeShape);
  CompositeShape(CompositeShape &&compositeShape);
  CompositeShape& operator=(const CompositeShape &other);
  CompositeShape& operator=(CompositeShape &&tmp);
  Shape* operator[](size_t id);
  const Shape* operator[](size_t id) const;
  ~CompositeShape();
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t point);
  void move(double delta_x, double delta_y);
  void scale(double k);
  point_t getCenter() const;
  void push_back(Shape *shp);
  void pop_back();
  Shape* at(size_t id);
  const Shape* at(size_t id) const;
  bool empty() const noexcept;
  size_t size() const noexcept;
private:
  size_t size_;
  size_t capacity_;
  Shape **shapes_;
};
std::istream& operator>>(std::istream &in, CompositeShape &compositeShape)
{
  size_t count = 0;
  in >> count;
  std::string line = "";
  std::string name = "";
  compositeShape = CompositeShape();
  for (size_t i = 0; i < count; i++)
  {
    std::getline(in, line);
    std::istringstream stream(line);
    stream >> name;
    if (name == "RECTANGLE")
    {
      Rectangle rect;
      stream >> rect;
      compositeShape.push_back(&rect);
    }
    else if (name == "REGULAR")
    {
      Regular regular;
      stream >> regular;
      compositeShape.push_back(&regular);
    }
    else if (name == "POLYGON")
    {
      Polygon polygon;
      stream >> polygon;
      compositeShape.push_back(&polygon);
    }
  }
  return in;
}
#endif
