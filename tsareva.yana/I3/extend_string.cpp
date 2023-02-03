#include <iostream>
#include "extend_string.h"
#include <limits>
#include <stdexcept>
#include "golden_ratio.h"

char *extendSrting(char* str_1, size_t & capacity_1, size_t size_1){
  size_t max_size_t = std::numeric_limits< size_t >::max();
  if (( max_size_t - (goldenRatio(capacity_1) - capacity_1)) >= capacity_1){
    throw std::invalid_argument("to much");
  }
}

