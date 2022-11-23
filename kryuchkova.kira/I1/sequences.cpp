#include "sequences.h"
#include <limits>
#include <stdexcept>

MaxCounter::MaxCounter()
{
  this->max = std::numeric_limits< int >::lowest();
  this->count_max = 0;
}

void MaxCounter::operator()(int current_value)
{
  if (current_value > this->max)
  {
    this->max = current_value;
    this->count_max = 1;
  }
  else if (current_value == this->max)
  {
    this->count_max++;
  }

  if (this->count_max == std::numeric_limits< int >::max())
  {
    throw std::overflow_error("Overflow!");
  }
}

MinCounter::MinCounter()
{
  this->min = std::numeric_limits< int >::max();
  this->count_min = 0;
}

void MinCounter::operator()(int current_value)
{
  if (current_value < this->min && current_value != 0)
  {
    this->min = current_value;
    this->count_min = 1;
  }
  else if (current_value == this->min)
  {
    this->count_min++;
  }

  if (this->count_min == std::numeric_limits< int >::max())
  {
    throw std::overflow_error("Overflow!");
  }
}
