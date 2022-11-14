#ifndef REPETEDNUMS_H
#define REPETEDNUMS_H
#include <cstddef>
namespace turkin
{
  struct RepeatedNums
  {
    bool operator()(const int * array, size_t size, int begin, int end);
  };
}
#endif
