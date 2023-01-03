#ifndef SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#define SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#include "shape.h"
class Concave: public Shape
{
public:
  Concave();
  explicit Concave(point_t *pointsArray);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  void scale(double k) override;
  void isoScale(Concave &concave, double x, double y, double k);
  Concave *clone() const override;
  bool goodConcaveInput() const;
  double *getSides() const;
  ~Concave() override = default;
private:
  mutable point_t A{}, B{}, C{}, D{};
};
#endif
