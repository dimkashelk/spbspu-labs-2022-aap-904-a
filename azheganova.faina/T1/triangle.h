#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "base_types.h"
#include "shape.h"

class Triangle : virtual public Shape
{
  public:
    Triangle();
    Triangle(point_t pos1, point_t pos2, point_t pos3);
    Triangle(const Triangle &tmp);
    Triangle(Triangle &&tmp);
    double getArea() const;
    rectangle_t getFrameRect() const;
    point_t findCenterOfTriangle();
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const override;
  private:
    point_t triangle1[3];
};

#endif
