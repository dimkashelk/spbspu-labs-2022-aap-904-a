#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "base_types.h"
#include "shape.h"

class triangle : virtual public shape
{
  public:
    triangle(point_t point1, point_t point2, point_t point3);
    double getArea() const;
    rectangle_t getFrameRect() const;
    point_t triangle::findCenterOfTriangle();
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k);
    shape * clone() const override;
  private:
    point_t triangle1[3];
};

#endif
