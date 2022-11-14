#ifndef DOWNSEQUENCE_H
#define DOWNSEQUENCE_H
#include <cstddef>
namespace turkin
{
  struct DownSequence
  {
    size_t operator()(const int * array, size_t size);
    size_t maxLen = 0;
    size_t curLen = 0;
  };
}
#endif
