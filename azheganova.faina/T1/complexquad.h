#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include "base_types.h"
#include "shape.h"

class Complexquad : virtual public Shape
{
  public:
    Complexquad();
    Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4);
    Complexquad(const Complexquad &tmp);
    Complexquad(Complexquad &&tmp);
    double getArea() const;
    rectangle_t getFrameRect() const;
    point_t findCenterOfTriangle();
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k);
    Shape * clone() const override;
  private:
    point_t complexquad1[5];
};

#endif
