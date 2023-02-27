#include "isExpression.h"
#include "cctype"
bool isDigit(const char c)
{
  return std::isdigit(c);
}
bool isLetter(const char c)
{
  return (c == 'a') || (c == 'b') || (c == 'c') || (c == 'd') || (c == 'e') || (c == 'f') || (c == 'x') || (c == 'y') || (c == 'z');
}
bool isEnd(const char c)
{
  return (c == '\0');
}
bool isSign(const char c)
{
  return (c == '+') || (c == '-');
}
bool isMulSign(const char c)
{
  return (c == '*');
}
bool isDivSign(const char c)
{
  return (c == '/');
}
bool isIndet(const char c)
{
  return isLetter(c);
}
bool isCloseBar(const char c)
{
  return (c == ')');
}
bool isOpenBar(const char c)
{
  return (c == '(');
}
bool isUnsigned(const char *data)
{
  return isDigit(*data) || (isDigit(*data) && (isUnsigned(data + 1)));
}
bool doMultip(const char *data)
{
  return isUnsigned(data) || isIndet(*data) || (isOpenBar(*data) && isExpression(data + 1) && isCloseBar(*data));
}
bool isTerm(const char *data)
{
  return doMultip(data) || (isOpenBar(*data) && isMulSign(*data) && isTerm(data + 1) && isCloseBar(*data))
    || (isOpenBar(*data) && isDivSign(*data) && isTerm(data + 1) && isCloseBar(*data));
}
bool isExpression(const char *data)
{
  return isEnd(*data) || isTerm(data) || (isTerm(data) && isSign(*data) && isExpression(data + 1));
}
