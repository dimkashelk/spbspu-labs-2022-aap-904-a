#ifndef SPBSPU_LABS_2022_AAP_904_A_PARALLELOGRAM_H
#define SPBSPU_LABS_2022_AAP_904_A_PARALLELOGRAM_H
#include "shape.h"
class Parallelogram: public Shape
{
public:
  explicit Parallelogram(const point_t &A, const point_t &B, const point_t &C);
  ~Parallelogram() override = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &position) override;
  void scale(double k) override;
  Shape *clone() const override;
private:
  bool goodParallelogramInput() const;
  point_t points_[3];
};
#endif
