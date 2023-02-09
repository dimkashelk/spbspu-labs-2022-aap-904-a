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

bool isOrder(const char* data)
{
  return isE(*data) && ((isSign(*(data + 1)) && continueWithDigit(data + 2)) || continueWithDigit(data + 1));
}
bool continueWithOrder(const char* data)
{
  return isOrder(data + 1) || (isDigit(*(data + 1)) && isOrder(data + 2));
}
bool isInteger(const char* data)
{
  return isDigit(*data) && ((continueWithDigit(data + 1) || continueWithOrder(data + 1)));
}

bool isFloat(const char* data)
{
  return isInteger(data) || (isSign(*data) && isInteger(data + 1));
}
