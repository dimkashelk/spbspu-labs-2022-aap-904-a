#ifndef POLYGON_HPP
#define POLYGON_HPP
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace chemodurov
{
  class Polygon: public chemodurov::Shape
  {
   public:
    Polygon(chemodurov::point_t * vertices, size_t number_of_vertices);
    ~Polygon();
    double getArea() const;
    chemodurov::rectangle_t getFrameRect() const;
    void move(const chemodurov::point_t & position);
    void move(double dx, double dy);
    void scale(double k);
   private:
    chemodurov::point_t * vertices_;
    size_t number_of_vertices_;
    chemodurov::point_t center_;
  };
}

#endif
