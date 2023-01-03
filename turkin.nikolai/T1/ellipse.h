#ifndef T1_ELLIPSE_H
#define T1_ELLIPSE_H
#include "shapesPatterns.h"
namespace turkin
{
  class Ellipse: virtual public Shape
  {
    public:
      Ellipse(point_t one, double nr1, double nr2);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(double dx, double dy) override;
      void move(point_t position) override;
      void scale(double ds) override;
    private:
      rectangle_t rect_;
      double r1, r2;
  };
}
#endif

