#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "Base-types.hpp"
#include "Shape.hpp"
#include <array>

class Concave : public Shape
{
public:
  Concave(point_t one, point_t two, point_t three, point_t four);

  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t position) override;
  void move(double dx, double dy) override;
  void makeScale(double value) override;

private:
  rectangle_t rect_;
  point_t one_;
  point_t two_;
  point_t three_;
  point_t four_;
  point_t points_[4];
  std::array< double, 6 > splitIntoTriangles() const;
  bool isGoodConcaveInput() const;
};

#endif
