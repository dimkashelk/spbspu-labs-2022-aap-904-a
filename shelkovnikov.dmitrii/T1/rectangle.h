#ifndef SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_RECTANGLE_H
#include <istream>
#include "shape.h"
class Rectangle: public Shape
{
public:
  Rectangle();
  Rectangle(rectangle_t rectangle);
  Rectangle(double x1, double y1, double x2, double y2);
  Rectangle(const Rectangle &rect);
  Rectangle(Rectangle &&rect);
  Rectangle& operator=(const Rectangle &other);
  Rectangle& operator=(Rectangle &&tmp) noexcept;
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double delta_x, double delta_y) override;
  void scale(double k) override;
  Shape* clone() const override;
private:
  rectangle_t rectangle_;
};
std::istream& operator>>(std::istream &in, Rectangle &rect)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  in >> x1 >> y1 >> x2 >> y2;
  rect = *(new Rectangle(x1, y1, x2, y2));
  return in;
}
#endif
