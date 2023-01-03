#include "expression.h"
#include <cctype>

bool isOpenBrace(const char data)
{
  return data == '(';
}
bool isCloseBrace (const char data)
{
  return data == ')';
}
bool isDigit(const char data)
{
  return std::isdigit(data);
}
bool isIdentificator(const char data)
{
  return data == 'a' || data == 'b' || data == 'c' || data == 'd' || data == 'e' || data == 'f' || data == 'x' || data == 'y' || data == 'z';
}
bool isEnd(const char data)
{
  return (data == '\0');
}
bool isSign(const char data)
{
  return data == '+' || data == '-' || data == '/' || data == '*';
}
