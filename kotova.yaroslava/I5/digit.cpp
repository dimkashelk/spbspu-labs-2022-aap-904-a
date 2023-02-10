#include "digit.hpp"
#include <cctype>
bool isSign(char c)
{
  return (c == '+' || c == '-');
}

bool isDigit(char c)
{
  return (std::isdigit(c));
}

bool isDot(char c)
{
  return (c == '.');
}

bool isEnd(char c)
{
  return (c == '\0');
}

bool isE(char c)
{
  return (c == 'E');
}

bool continueWithDigit(const char* data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || isEnd(*(data + 1)));
}

bool continueWithDigit(const char* data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || isEnd(*(data + 1)));
}

bool isOrder(const char* data)
{
  return isE(*data) && (isSign(*(data + 1)) && continueWithDigit(data + 2) || continueWithDigit(data + 1));
}

bool AfterDot(const char* data)
{
  return isDot(*data) && isOrder(data + 1);
}

bool isMantissa(const char* data)
{
  return isDigit(*data) && AfterDot(data + 1);
}
bool isInteger(const char* data)
{
  return isDigit(*data) && (continueWithDigit(data + 1) || isMantissa((data + 1)));
}

bool isFloat(const char* data)
{
  return isInteger(data) || (isSign(*data) && isInteger(data + 1));
}
