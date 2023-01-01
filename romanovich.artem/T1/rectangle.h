#ifndef SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#include "shape.h"
class Rectangle : public Shape
{
public:
  Rectangle();
  explicit Rectangle(point_t *pointsArray);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  void scale(double k) override;
  static void isoScale(Rectangle rectangle, double x, double y, double k);
  Rectangle *clone() const override;
  ~Rectangle() override = default;
private:
  mutable point_t A{}, B{}, C{}, D{};//mutable point_t points[4];
};
#endif
