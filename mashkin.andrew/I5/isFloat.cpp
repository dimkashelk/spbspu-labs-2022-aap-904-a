#include "isFloat.h"

bool isFloat(const char* string)
{
  return isMantissa(string) || (isSign(*string) && isMantissa(string + 1));
}
