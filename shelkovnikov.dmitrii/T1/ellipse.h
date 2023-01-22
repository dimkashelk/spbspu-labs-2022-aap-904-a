#ifndef T1_ELLIPSE_H
#define T1_ELLIPSE_H
#include "shape.h"
#include "triangle.h"
namespace dimkashelk
{
  class Ellipse: public Shape
  {
  public:
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t point) override;
    void move(double delta_x, double delta_y) override;
    void scale(double k) override;
    void unsafeScale(double k) noexcept override;
    Shape* clone() const override;
  private:
    Triangle *triangles;
  };
}
#endif
