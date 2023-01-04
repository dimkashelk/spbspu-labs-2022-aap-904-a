#ifndef SPBSPU_LABS_2022_AAP_904_A_PARALLELOGRAM_H
#define SPBSPU_LABS_2022_AAP_904_A_PARALLELOGRAM_H
#include "shape.h"
class Parallelogram : public Shape
{
public:
  explicit Parallelogram(point_t A, point_t B, point_t C);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  void scale(double k) override;
  Shape *clone() const override;
  ~Parallelogram() override = default;
private:
  bool goodParallelogramInput() const;
  point_t A, B, C, D;
  void isoScale(Parallelogram &parallelogram, double x, double y, double k);
};
#endif
