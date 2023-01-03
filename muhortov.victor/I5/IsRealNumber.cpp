#include "IsRealNumber.hpp"
#include <cctype>

bool findDot(const char *);
bool afterDot(const char *);
bool findE(const char *);
bool findSign(const char *);
bool afterSign(const char *);
bool finish(const char *);

bool isSign(char x)
{
  return x == '+' || x == '-';
}

bool isDigit(char x)
{
  return std::isdigit(x);
}

bool isE(char x)
{
  return x == 'E';
}

bool isDot(char x)
{
  return x == '.';
}

bool isEnd(char x)
{
  return x == '\0';
}

bool start(const char *x)
{
  return isDigit(*x) && (start(++x) || findDot(++x));
}
bool findDot(const char *x)
{
  return isDot(*x) && afterDot(++x);
}
bool afterDot(const char *x)
{
  return isDigit(*x) && (afterDot(++x) || findE(++x));
}
bool findE(const char *x)
{
  return isE(*x) && (findSign(++x) || afterSign(++x) || finish(++x));
}
bool findSign(const char *x)
{
  return isSign(*x) && (afterSign(++x) || finish(++x));
}
bool afterSign(const char *x)
{
  return isDigit(*x) && (afterSign(++x) || finish(++x));
}
bool finish(const char *x)
{
  return isDigit(*x) && isEnd(*(++x));
}

bool isRealNum(const char *x)
{
  bool first_variant = isSign(*x) && (start(++x) || findDot(++x));
  bool second_variant = isDigit(*x) && (start(++x) || findDot(++x));
  bool third_variant = isDot(*x) && afterDot(++x);

  return first_variant || second_variant || third_variant;
}
