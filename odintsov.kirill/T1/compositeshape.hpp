#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace odintsov {
  class CompositeShape {
    public:
      CompositeShape();
      explicit CompositeShape(size_t cap);
      CompositeShape(const CompositeShape& shp);
      CompositeShape(CompositeShape&& shp);
      ~CompositeShape();

      CompositeShape& operator=(const CompositeShape& shp);
      CompositeShape& operator=(CompositeShape&& shp);
      odintsov::Shape* operator[](size_t id) const;

      double getArea() const;
      rectangle_t getFrameRect() const;
      void move(double dx, double dy);
      void move(const point_t& pos);
      void scale(double k);
      point_t getMiddlePoint() const;

      void push_back(odintsov::Shape* shp);
      void pop_back();
      odintsov::Shape* at(size_t id) const;
      bool empty() const;
      size_t size() const;
    private:
      size_t size_;
      size_t cap_;
      Shape** shapes;
      void extend(size_t newCap);
  };
}

#endif
