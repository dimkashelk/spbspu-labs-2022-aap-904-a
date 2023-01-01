#ifndef SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#include "shape.h"
class Rectangle : public Shape
{
public:
  Rectangle(point_t A_, point_t B_, point_t C_, point_t D_);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  void scale(double k) override;
  Rectangle *clone() const override;
  ~Rectangle() override = default;
private:
  point_t A, B, C, D;
  //point_t points[3] = pointsArray;
};
#endif
