#include "iostream"
bool isZero(char c)
{
  return (c == '0');
}
bool isNumberSign(char c)
{
  return (c == '+') || (c == '-');
}
bool isDigit(char c)
{
  return std::isdigit(c);
}
bool isStringEnd(char c)
{
  return (c == '\0');
}
bool isDot(char c)
{
  return (c == '.') || (c == ',');
}
bool isLetterE(char c)
{
  return (c == 'E');
}
bool isUnsignedInteger(const char *data)
{
  return isDigit(*data) && (isDigit(*data) && isUnsignedInteger(data + 1) || isStringEnd(*(data + 1)));
}
bool isSignificand(const char *data)
{
  return isUnsignedInteger(data + 1) || (isDot(*data) && isUnsignedInteger(data + 1));
}
bool isBase(const char *data)
{
  return (isLetterE(*data) && isNumberSign(*(data + 1)) && isUnsignedInteger(data + 2)) ||
         (isLetterE(*data) && isUnsignedInteger(data + 1));
}
bool isFloat(const char *data)
{
  return !isZero(*data) && (isSignificand(data) && isBase(data)) ||
         (isNumberSign(*data) && isSignificand(data) && isBase(data));
}
int main()
{
  const char *testArr[] = {
    "5",
    "-6",
    "333333335",
    ".33335",
    "3.33335",
    "555.5555",
    "555.55.55",
    ".123E2",
    ".123E-9",
    ".123E+12",
    "E-9",
    "E-",
    "E3",
    "E33245364",
    "E",
    "E+12"
  };
  for (auto test: testArr)
  {
    std::cout << isBase(test) << " " << test << "\n";
  }
}
