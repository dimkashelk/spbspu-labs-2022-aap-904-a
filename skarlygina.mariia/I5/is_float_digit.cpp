#include "is_float_digit.h"
#include <cctype>

bool isSign(char c)
{
  return (c == '+' || c == '-');
}

bool isDigit(char c)
{
  return std::isdigit(c);
}

bool isE(char c)
{
  return (c == 'E');
}

bool isDot(char c)
{
  return (c == '.');
}

bool isEnd(char c)
{
  return (c == '\0');
}

bool isDigitWithNoSign(const char* data)
{
  return (isDigit(*data) || (isDigit(*data) && (isDigitWithNoSign(data + 1) || isEnd(*(data + 1)))));
}

bool isOrder(const char* data)
{
  return (isE(*data) && isSign(*(data + 1)) && isDigitWithNoSign(data + 2));
}

bool isMantissa(const char* data)
{
  return ((isDigitWithNoSign(data) && isDot(*(data + 1)) && isDigitWithNoSign(data + 2)) || (isDot(*data) && isDigitWithNoSign(data + 1)));
}

bool isFloatDigit(const char* data)
{
  return (isSign(*data) && isMantissa(data + 1) && isOrder(data + 2));
}
