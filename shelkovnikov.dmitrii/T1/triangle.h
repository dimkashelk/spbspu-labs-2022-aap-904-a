#ifndef SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#define SPBSPU_LABS_2022_AAP_904_A_TRIANGLE_H
#include "shape.h"
class Triangle: virtual public Shape
{
public:
  Triangle();
  Triangle(point_t point1, point_t point2, point_t point3);
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
  Triangle(const Triangle &triangle);
  Triangle(Triangle &&triangle);
  Triangle& operator=(const Triangle &other);
  Triangle& operator=(Triangle &&tmp);
  double getArea() const override;
  rectangle_t getFrameRect() const override;
  void move(point_t point) override;
  void move(double delta_x, double delta_y) override;
  void scale(double k) override;
  Shape* clone() const override;
  bool isRectangular();
  point_t* getPoints() const;
  point_t getCenter() const;
  bool containsPoint(point_t point) const;
private:
  point_t point1_;
  point_t point2_;
  point_t point3_;
};
std::istream& operator>>(std::istream &in, Triangle &triangle);
#endif
