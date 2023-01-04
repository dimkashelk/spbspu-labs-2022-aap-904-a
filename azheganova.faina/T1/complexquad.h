#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include "base_types.h"
#include "shape.h"

class complexquad : virtual public shape
{
  public:
    complexquad();
    complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4);
    complexquad(const complexquad &tmp);
    complexquad(complexquad &&tmp);
    double getArea() const;
    rectangle_t getFrameRect() const;
    point_t findCenterOfTriangle();
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k);
    shape * clone() const override;
  private:
    point_t complexquad1[5];
};

#endif
