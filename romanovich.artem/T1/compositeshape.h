#ifndef SPBSPU_LABS_2022_AAP_904_A_COMPOSITESHAPE_H
#define SPBSPU_LABS_2022_AAP_904_A_COMPOSITESHAPE_H
#include <cstddef>
#include "base-types.h"
#include "shape.h"
class CompositeShape
{
public:
  CompositeShape(const CompositeShape &rhs);
  CompositeShape(CompositeShape &&rhs) noexcept;
  explicit CompositeShape(size_t capacity);
  ~CompositeShape();
  CompositeShape &operator=(const CompositeShape &rhs);
  CompositeShape &operator=(CompositeShape &&rhs) noexcept;
  Shape *operator[](size_t id);
  Shape *at(size_t id);
  double getArea() const;
  rectangle_t getFrameRect();
  void move(double dx, double dy);
  void move(point_t position);
  void scale(double k);
  void scale(const point_t &position, double k);
  void unsafeIsoScale(const point_t &position, double k) noexcept;
  void push_back(Shape *shp);
  void push_back(const Shape *shp);
  void pop_back();
  bool empty() const noexcept;
  size_t size() const noexcept;
private:
  Shape **shape_;
  size_t size_;
  size_t capacity_;
};
#endif
