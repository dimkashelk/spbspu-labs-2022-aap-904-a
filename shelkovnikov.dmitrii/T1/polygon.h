#ifndef SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#define SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#include <cstddef>
#include "triangle.h"
class Polygon: virtual public Shape
{
public:
  Polygon(point_t *points, size_t size);
  Polygon(Polygon &&polygon);
  ~Polygon();
  Polygon& operator=(const Polygon &other);
  Polygon& operator=(Polygon &&tmp);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double delta_x, double delta_y) override;
  void scale(double k) override;
  Shape* clone() const override;
private:
  size_t count_;
  Triangle *triangles_;
  Polygon(const Polygon &polygon);
  Triangle* makeTriangles(point_t *points, size_t size);
  point_t getCenter() const;
};
#endif
