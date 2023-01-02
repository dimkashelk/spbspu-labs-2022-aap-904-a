#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base_types.h"
#include "shape.h"

class rectangle : virtual public shape
{
  public:
    explicit rectangle(point_t *inputRectangle);
    rectangle(rectangle_t rectangle);
    rectangle(point_t point1, point_t point2);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(double k);
    shape * clone() const;
  private:
    rectangle_t rectangle1;
    point_t x1{};
    point_t y1{};
    point_t x2{};
    point_t y2{};
};

#endif
