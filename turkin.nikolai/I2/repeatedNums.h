#ifndef REPETEDNUMS_H
#define REPETEDNUMS_H
#include "dynamicArray.h"
#include <cstddef>
namespace turkin
{
  bool getRepeatedNums(const Array & array, size_t begin, size_t end);
  bool getRepeatedNums(const int * array, size_t size, size_t begin, size_t end);
}
#endif
