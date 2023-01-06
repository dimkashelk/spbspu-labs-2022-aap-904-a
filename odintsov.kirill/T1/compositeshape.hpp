#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <cstddef>
#include "base-types.hpp"

namespace odintsov {
  class CompositeShape {
    public:
      explicit CompositeShape(size_t cap);

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);

      void push_back(Shape* shp);
      void pop_back();
      Shape* at(size_t id);
      Shape* operator[](size_t id);
      bool empty();
      size_t size() const;
    private:
      size_t size;
      size_t cap;
      Shape* shapes;
  }
}

#endif
