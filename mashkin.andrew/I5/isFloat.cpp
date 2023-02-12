#include "isFloat.h"

bool isFloat(const char* string)
{
  return isMantissa(string) || (isSign(*string) && isMantissa(string + 1));
}
bool isMantissa(const char* string)
{
  return (isDot(*(string)) && isUnsignedInteger(string + 1)) || isUnsignedInteger(string);
}
bool isSign(char symb)
{
  return symb == '+' || symb == '-';
}