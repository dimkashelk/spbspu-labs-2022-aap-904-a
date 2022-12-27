#ifndef SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#define SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#include <cstddef>
#include "triangle.h"
class Polygon: virtual public Shape
{
public:
  Polygon();
  Polygon(point_t *points, size_t size);
  Polygon(const Polygon &polygon);
  Polygon(Polygon &&polygon);
  Polygon& operator=(const Polygon &other);
  Polygon& operator=(Polygon &&tmp);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double delta_x, double delta_y) override;
  void scale(double k) override;
  Shape* clone() const override;
  point_t getCenter() const;
private:
  Triangle **triangles_;
  size_t count_;
};
std::istream& operator>>(std::istream &in, Polygon &polygon);
#endif
