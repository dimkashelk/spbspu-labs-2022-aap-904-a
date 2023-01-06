#ifndef T1_RECTANGLE_H
#define T1_RECTANGLE_H
#include "base-types.h"
#include "shape.h"
namespace turkin
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(point_t one, point_t two);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double dx, double dy) override;
      void move(point_t position) override;
      void scaleW(double ds) override;
    private:
      rectangle_t rect_;
  };
}
#endif

