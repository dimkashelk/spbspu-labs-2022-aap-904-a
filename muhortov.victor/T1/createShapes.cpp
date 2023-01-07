#include "createShapes.hpp"
#include <stdexcept>
#include "rectangle.hpp"
#include "ring.hpp"
#include "concave.hpp"

void checkingInput(std::istream  &input)
{
  if(!input)
  {
    throw std::invalid_argument("Invalid argument");
  }
}

Shape *createRectangle(std::istream &input)
{
  double positions[4] {0.0, 0.0, 0.0, 0.0};
  input >> positions[0] >> positions[1] >> positions[2] >> positions[3];
  checkingInput(input);
  return new Rectangle({positions[0], positions[1]},{positions[2], positions[3]});
}

Shape *createRing(std::istream &input)
{
  double positions[4] {0.0, 0.0, 0.0, 0.0};
  input >> positions[0] >> positions[1] >> positions[2] >> positions[3];
  checkingInput(input);
  return new Ring({positions[0], positions[1]},positions[2], positions[3]);
}

Shape *createConcave(std::istream &input)
{
  double positions[8] {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  input >> positions[0] >> positions[1] >> positions[2] >> positions[3] >> positions[4] >> positions[5] >> positions[6] >> positions[7];
  checkingInput(input);
  return new Concave({positions[0], positions[1]}, {positions[2], positions[3]}, {positions[4], positions[5]}, {positions[6], positions[7]});
}

scale_t getScale(std::istream &input)
{
  double positions[3] {0.0, 0.0, 0.0};
  input >> positions[0] >> positions[1] >> positions[2];
  checkingInput(input);
  if (positions[2] < 0.0)
  {
    throw std::invalid_argument("invalid scale size");
  }
  return {{positions[0], positions[1]}, positions[2]};
}
