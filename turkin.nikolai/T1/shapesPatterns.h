#ifndef T1_SHAPESPATTERNS_H
#define T1_SHAPESPATTERNS_H
#include <cstddef>
namespace turkin
{
  struct point_t
  {
    point_t(double x, double y);
    double x, y;
  };

  struct rectangle_t
  {
    rectangle_t(point_t one, point_t two);
    rectangle_t(point_t one, double side);
    rectangle_t(point_t one, double r1, double r2);
    point_t position;
    double width, height;
  };

  struct scale_t
  {
    scale_t(point_t one, double nscale);
    point_t position;
    double scale;
  };

  class Shape
  {
    public:
      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() const = 0;
      virtual void move(double dx, double dy) = 0;
      virtual void move(point_t position) = 0;
      virtual void scale(double ds) = 0;
      virtual ~Shape() = default;
  };
  /*
  class CompositeShape
  {
    public:
      void push_back(Shape * shp);
      void pop_back();
      Shape * at(size_t id);
      Shape * operator[](size_t id);
      bool empty();
      size_t size();
  };
   */
}

#endif
