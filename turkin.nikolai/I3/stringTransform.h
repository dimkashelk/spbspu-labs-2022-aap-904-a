#ifndef STRINGTRANSFORM_H
#define STRINGTRANSFORM_H
#include <cstddef>
#include "charArray.h"
namespace turkin
{
  char * deleteNumbers(char * destination, const char * source, size_t size);
  bool isRepeat(const turkin::CharArray & array);
}
#endif
