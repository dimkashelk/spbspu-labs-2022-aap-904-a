#ifndef SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#define SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#include <cstddef>
#include "triangle.h"
class Polygon: public Shape
{
public:
  Polygon(point_t *points, size_t size);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double delta_x, double delta_y) override;
  void scale(double k) override;
  point_t getCenterOfGravity() const;
private:
  Triangle **triangles;
  size_t count;
};
#endif
