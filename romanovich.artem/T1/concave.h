#ifndef SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#define SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#include <array>
#include "shape.h"
class Concave: public Shape
{
public:
  explicit Concave(point_t A, point_t B, point_t C, point_t D);
  ~Concave() override = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(point_t position) override;
  void scale(double k) override;
  Shape *clone() const override;
private:
  std::array<double, 6> splitIntoTriangles() const;
  bool goodConcaveInput() const;
  point_t A_, B_, C_, D_;
};
#endif
