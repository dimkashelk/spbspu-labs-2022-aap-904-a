#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include <iostream>
#include "base_types.h"
#include "shape.h"
#include "triangle.h"

Shape* inputComplexquad(std::istream &input);

class Complexquad: virtual public Shape
{
  public:
    Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    point_t findCenterOfTriangle();
    void move(point_t position);
    void move(double dx, double dy);
    void scale(double k) noexcept;
    Shape * clone() const override;
  private:
    point_t triangle1[3];
    point_t triangle2[3];
};

#endif
