#ifndef SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#define SPBSPU_LABS_2022_AAP_904_A_POLYGON_H
#include <cstddef>
#include "triangle.h"
namespace dimkashelk
{
  class Polygon: public Shape
  {
  public:
    Polygon(point_t *points, size_t size);
    ~Polygon();
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double delta_x, double delta_y) override;
    void scale(double k) override;
    Shape* clone() const override;
  private:
    size_t count_;
    Triangle *triangles_;
    point_t center_;
    Polygon(const Polygon &polygon);
    Polygon(Polygon &&polygon) = delete;
    Polygon& operator=(const Polygon &other) = delete;
    Polygon& operator=(Polygon &&tmp) = delete;
    Triangle* makeTriangles(point_t *points, size_t size);
  };
}
#endif
