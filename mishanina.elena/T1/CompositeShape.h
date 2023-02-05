#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include "base-types.h"
#include "shape.h"
#include <string>
#include <cstddef>

class CompositeShape : public Shape
{
public:
  CompositeShape(Shape** shapes, std::size_t capacity, std::size_t size, std::string name);
  CompositeShape();
  CompositeShape(const CompositeShape& compositeShape);
  CompositeShape(CompositeShape&& compositeShape) noexcept;
  CompositeShape& operator = (const CompositeShape& compositeShape);
  CompositeShape& operator = (CompositeShape&& compositeShape) noexcept;
  ~CompositeShape();
  Shape* operator[](std::size_t index);
  const Shape* operator[](std::size_t index) const;
  double getArea() const;
  void move(point_t point);
  void move(double dx, double dy);
  void scale(double k);
  CompositeShape* clone() const;
  void push_back(Shape* shape);
  void pop_back();
  Shape* at(std::size_t index);
  const Shape* at(std::size_t index) const;
  bool empty() const;
  std::size_t size() const;
  rectangle_t getFrameRect() const;
  std::string getName() const override;
private:
  std::string name_;
  std::size_t size_;
  std::size_t capacity_;
  Shape** shapes_;
  void remove(Shape** shapes, std::size_t size) const;
};

#endif
