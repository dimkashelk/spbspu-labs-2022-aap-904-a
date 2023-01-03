#ifndef SPBSPU_LABS_2022_AAP_904_A_PARALLELOGRAM_H
#define SPBSPU_LABS_2022_AAP_904_A_PARALLELOGRAM_H
#include "shape.h"
class Parallelogram: public Shape
{
public:
  Parallelogram();
  explicit Parallelogram(point_t *pointsArray);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  void scale(double k) override;
  void isoScale(Parallelogram &parallelogram, double x, double y, double k);
  Parallelogram *clone() const override;
  ~Parallelogram() override = default;
  bool goodParallelogramInput() const;
private:
  mutable point_t A{}, B{}, C{}, D{};
};
#endif
