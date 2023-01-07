#include "createShapes.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "ring.hpp"
#include "concave.hpp"

Shape *createRectangle(std::istream &input)
{
  double positions[4] {0.0, 0.0, 0.0, 0.0};
  input >> positions[0] >> positions[1] >> positions[2] >> positions[3];
  return new Rectangle({positions[0], positions[1]},{positions[2], positions[3]});
}

Shape *createRing(std::istream &input)
{
  double positions[4] {0.0, 0.0, 0.0, 0.0};
  input >> positions[0] >> positions[1] >> positions[2] >> positions[3];
  return new Ring({positions[0], positions[1]},positions[2], positions[3]);
}

Shape *createConcave(std::istream &input)
{
  double positions[8] {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  try
  {
    input >> positions[0] >> positions[1] >> positions[2] >> positions[3] >> positions[4] >> positions[5] >> positions[6]
          >> positions[7];
  }
  catch (...)
  {
    throw std::invalid_argument("Error test");
  }
  return new Concave({positions[0], positions[1]}, {positions[2], positions[3]}, {positions[4], positions[5]}, {positions[6], positions[7]});
}

scale_t getScale(std::istream &input)
{
  double positions[3] {0.0, 0.0, 0.0};
  input >> positions[0] >> positions[1] >> positions[2];
  if (positions[2] < 0.0)
  {
    throw std::invalid_argument("invalid scale size");
  }
  return {{positions[0], positions[1]}, positions[2]};
}
