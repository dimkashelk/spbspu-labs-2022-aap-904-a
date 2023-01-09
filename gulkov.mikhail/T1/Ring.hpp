#ifndef RING_HPP
#define RING_HPP

#include "Base-types.hpp"
#include "Shape.hpp"
#include "Ellipse.hpp"

class Ring: public Shape
{
public:
  Ring(point_t center, Shape *EllipseOne, Shape *EllipseTwo);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t newpos) override;
  void move(double delta_x, double delta_y) override;
  void makeScale(double k) override;
  Shape *clone() const override;
private:
  point_t center_;
  rectangle_t rect_;
  Shape *EllipseOne_;
  Shape *EllipseTwo_;

  //надо тут эллипсы создавать а не в другом месте, их же можно будет деструктором удалить. Осталось не забыть все это сделать
};

#endif
