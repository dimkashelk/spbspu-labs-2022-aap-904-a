#include "IsRealNumber.hpp"
#include <cctype>

bool findDot(char *);
bool afterDot(char *);
bool findE(char *);
bool findSign(char *);
bool afterSign(char *);
bool finish(char *);

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

bool start(char *x)
{
  return isDigit(*x) && (start(++x) || findDot(++x));
}
bool findDot(char *x)
{
  return isDot(*x) && afterDot(++x);
}
bool afterDot(char *x)
{
  return isDigit(*x) && (afterDot(++x) || findE(++x));
}
bool findE(char *x)
{
  return isE(*x) && (findSign(++x) || afterSign(++x) || finish(++x));
}
bool findSign(char *x)
{
  return isSign(*x) && (afterSign(++x) || finish(++x));
}
bool afterSign(char *x)
{
  return isDigit(*x) && (afterSign(++x) || finish(++x));
}
bool finish(char *x)
{
  return isDigit(*x) && isEnd(*(++x));
}

bool isRealNum(char *x)
{
  bool first_variant = isSign(*x) && (start(++x) || findDot(++x));
  bool second_variant = isDigit(*x) && (start(++x) || findDot(++x));
  bool third_variant = isDot(*x) && afterDot(++x);

  return first_variant || second_variant || third_variant;
}
