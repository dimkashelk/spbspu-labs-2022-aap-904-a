#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include "shape.hpp"

namespace chemodurov
{
  class CompositeShape
  {
   public:
    CompositeShape(chemodurov::Shape ** shape, size_t size, size_t capacity);
    ~CompositeShape();
    chemodurov::Shape * operator[](size_t id);
    chemodurov::Shape * at(size_t id);
    void push_back(chemodurov::Shape * shp);
    void pop_back();
    bool empty();
    size_t size();
    double getArea() const;
    chemodurov::rectangle_t getFrameRect() const;
    void move(const chemodurov::point_t & position);
    void move(double dx, double dy);
    void scale(double k);
    void scale(const chemodurov::point_t & position, double k);
   private:
    chemodurov::Shape ** shape_;
    size_t size_;
    size_t capacity_;
  };
}

#endif
