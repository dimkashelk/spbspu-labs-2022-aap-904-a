#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "base_types.h"
#include "shape.h"

class triangle : virtual public shape
{
  public:
    triangle();
    triangle(const triangle &tmp);
    triangle(triangle &&tmp);
    double getArea() const;
    rectangle_t getFrameRect() const;
    point_t findCenterOfTriangle();
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k);
    shape * clone() const override;
  private:
    point_t triangle1[3];
};

#endif
