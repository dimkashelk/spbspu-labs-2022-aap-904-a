#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
class Rectangle: public Shape {
 public:
  Rectangle(const point_t &point1, const point_t &point2);
  explicit Rectangle(const rectangle_t &rect);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double dx, double dy);
  void move(const point_t &pos);
  void scale(double k);
 private:
  rectangle_t rect;
};
#endif
