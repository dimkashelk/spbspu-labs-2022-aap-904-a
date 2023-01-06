#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base_types.h"
#include "shape.h"

class Rectangle : virtual public Shape
{
  public:
    Rectangle(rectangle_t rectangle);
    Rectangle(point_t point1, point_t point2);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k) noexcept;
    Shape * clone() const override;
  private:
    rectangle_t rectangle1;
};

#endif
