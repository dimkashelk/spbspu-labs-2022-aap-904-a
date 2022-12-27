#include "extend-shape-ptr-array.hpp"
#include <stdexcept>

chemodurov::Shape ** extendShapePtrArray(chemodurov::Shape ** shp, size_t cap, size_t new_cap)
{
  if (new_cap <= cap)
  {
    throw std::logic_error("New capacity less then old");
  }
  chemodurov::Shape ** new_shp = new chemodurov::Shape*[new_cap];
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
