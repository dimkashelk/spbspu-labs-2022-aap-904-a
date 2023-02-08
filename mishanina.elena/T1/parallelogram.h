#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "base-types.h"
#include "shape.h"
#include <string>

class Parallelogram : public Shape
{
public:
  Parallelogram(const point_t& A, const point_t& B, const point_t& C);
  std::string getName() const;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void scale(double k) override;
  void move(double dx, double dy) override;
  Shape* clone() const override;

private:
  const char* name_;
  point_t A_, B_, C_;
};

#endif
