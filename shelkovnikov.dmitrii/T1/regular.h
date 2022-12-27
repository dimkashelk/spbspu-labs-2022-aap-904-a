#ifndef SPBSPU_LABS_2022_AAP_904_A_REGULAR_H
#define SPBSPU_LABS_2022_AAP_904_A_REGULAR_H
#include <cstddef>
#include "shape.h"
#include "triangle.h"
class Regular: public Shape
{
public:
  Regular();
  Regular(double x1, double y1, double x2, double y2, double x3, double y3);
  Regular(const Regular &regular);
  Regular(Regular &&regular);
  Regular& operator=(const Regular &other);
  Regular& operator=(Regular &&tmp);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double delta_x, double delta_y) override;
  void scale(double k) override;
  Shape* clone() const override;
private:
  Triangle triangle_;
  size_t size_;
};
std::istream& operator>>(std::istream &in, Regular &regular)
{
  Triangle triangle;
  in >> triangle;
  point_t *points = triangle.getPoints();
  regular = *(new Regular(points[0].x, points[0].y, points[1].x, points[1].y, points[2].x, points[2].y));
  return in;
}
#endif
