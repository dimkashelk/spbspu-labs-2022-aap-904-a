#include "extend-shape-ptr-array.hpp"
#include <stdexcept>

chemodurov::Shape ** chemodurov::extendShapePtrArray(Shape ** shp, size_t cap, size_t new_cap)
{
  if (new_cap <= cap)
  {
    throw std::logic_error("New capacity less then old");
  }
  Shape ** new_shp = new Shape*[new_cap];
  for (size_t i = 0; i < new_cap; ++i)
  {
    if (i < cap)
    {
      new_shp[i] = shp[i];
    }
    else
    {
      new_shp[i] = nullptr;
    }
  }
  return new_shp;
}
