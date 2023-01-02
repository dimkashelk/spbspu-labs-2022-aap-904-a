#ifndef SHAPE_H
#define SHAPE_H
#include "base-types.h"

class shape
{
  public:
    double getArea();
    rectangle_t getFrameRect();
    void move();
    void scale();
    void getName();
    void clone();
};

#endif