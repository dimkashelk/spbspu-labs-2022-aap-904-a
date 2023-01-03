#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "base_types.h"
#include "shape.h"

class rectangle : public shape
{
  public:
    rectangle(rectangle *arr);
    rectangle(rectangle_t rectangle);
    rectangle(point_t point1, point_t point2);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t position);
    void scale(double k);
    rectangle * clone() const override;
  private:
    rectangle_t rectangle1;
};

#endif
