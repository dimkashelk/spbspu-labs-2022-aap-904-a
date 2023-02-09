#include "IsReal.h"

bool isSign(char chr)
{
  return chr == '+' || chr == '-';
}

bool isDigit(char chr)
{
  return chr >= 48 && chr <= 57;
}

bool isUInt(char*& str)
{
  return (isDigit(*str) && isDigit(*++str) && isUInt(str)) || isDigit(*(str - 1));
}

bool isMantissa(char*& str)
{
  return str[0] == '.' && isUInt(++str);
}

bool isOrder(char* str)
{
  return *str == 'E' && ((isSign(*++str) && isUInt(++str)) || isUInt(str));
}

bool isReal(char* str)
{
  return (isSign(str[0]) && isMantissa(++str) && isOrder(str)) || (isMantissa(str) && isOrder(str));
}
