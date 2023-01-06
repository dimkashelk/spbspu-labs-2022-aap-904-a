#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace odintsov {
  class CompositeShape {
    public:
      explicit CompositeShape(size_t cap);
      ~CompositeShape();

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
      point_t getMiddlePoint() const;

      void push_back(odintsov::Shape* shp);
      void pop_back();
      odintsov::Shape* at(size_t id) const;
      odintsov::Shape* operator[](size_t id) const;
      bool empty() const;
      size_t size() const;
    private:
      void extend(size_t newCap);
      size_t size_;
      size_t cap_;
      Shape** shapes;
  };
}

#endif
