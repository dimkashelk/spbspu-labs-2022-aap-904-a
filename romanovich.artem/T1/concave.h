#ifndef SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#define SPBSPU_LABS_2022_AAP_904_A_CONCAVE_H
#include "shape.h"
#include <array>
class Concave: public Shape
{
public:
  explicit Concave(const point_t &A, const point_t &B, const point_t &C, const point_t &D);
  ~Concave() override = default;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(double dx, double dy) override;
  void move(const point_t &position) override;
  void scale(double k) override;
  Shape *clone() const override;
private:
  std::array<double, 6> splitIntoTriangles() const;
  bool goodConcaveInput() const;
  static double buildLineFromTwoDots(const point_t &p1, const point_t &p2);
  point_t a_, b_, c_, d_;
};
#endif
