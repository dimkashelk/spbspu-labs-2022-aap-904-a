#ifndef STRINGTRANSFORM_H
#define STRINGTRANSFORM_H
#include <cstddef>
#include "cString.h"
namespace turkin
{
  char * deleteNumbers(char * destination, const char * source, size_t size);
  bool isRepeat(const turkin::String & string);
}
#endif
