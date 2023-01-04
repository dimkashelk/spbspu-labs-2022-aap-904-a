#ifndef SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#define SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#include "shape.h"
class Concave : public Shape
{
public:
  explicit Concave(point_t A, point_t B, point_t C, point_t D);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  void scale(double k) override;
  Concave *clone() const override;
  double *getSides() const;
  ~Concave() override = default;
private:
  bool goodConcaveInput() const;
  point_t A{}, B{}, C{}, D{};
  void isoScale(Concave &concave, double x, double y, double k);
};
#endif
