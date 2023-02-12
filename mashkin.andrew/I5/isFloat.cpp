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
bool isUnsignedInteger(const char* string)
{
  return isDigit(*string) && (isUnsignedInteger(string + 1) || isOrder(string + 1) || isEnd(*(string + 1))) || (isDigit(*string) && isEnd(*(string + 1)));
}
bool isDigit(char symb)
{
  return std::isdigit(symb);
}
bool isOrder(const char* string)
{
  return (isE(*string) && isSign(*(string + 1)) && isUnsignedInteger(string + 2)) || (isE(*string) && isUnsignedInteger(string + 1));
}
bool isEnd(char symb)
{
  return symb == '\0';
}
bool isE(char symb)
{
  return symb == 'E' || symb == 'e';
}