#ifndef T1_RECTANGLE_H
#define T1_RECTANGLE_H
#include "shapesPatterns.h"
namespace turkin
{
  class Rectangle: virtual public Shape
  {
    public:
      Rectangle(point_t one, point_t two);
      Rectangle(point_t one, double side);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double dx, double dy) override;
      void move(point_t position) override;
      void scale(double ds) override;
    private:
      rectangle_t rect_;
  };
}
#endif
