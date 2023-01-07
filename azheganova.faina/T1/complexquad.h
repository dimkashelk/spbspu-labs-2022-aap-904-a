#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include "base_types.h"
#include "shape.h"

class Complexquad : virtual public Shape
{
  public:
    point_t findCenter(point_t pos1, point_t pos2, point_t pos3, point_t pos4);
    Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    point_t findCenterOfTriangle();
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k) noexcept;
    Shape * clone() const override;
  private:
    point_t complexquad1[5];
    point_t findCenter(point_t pos1, point_t pos2, point_t pos3, point_t pos4);
};

#endif
