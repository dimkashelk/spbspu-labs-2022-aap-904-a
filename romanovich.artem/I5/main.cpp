#include "iostream"
bool isUnsignedInteger1(const char *data);
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
bool isUnsignedInteger2(const char *data)
{
  return isDigit(*data) && (isDigit(*data) && isUnsignedInteger2(data + 1) || isStringEnd(*(data + 1)));
}
bool isSignificand(const char *data)
{
  return isUnsignedInteger1(data + 1) || isUnsignedInteger2(data + 1) ||
         (isDot(*data) && isUnsignedInteger1(data + 1));
}
bool isBase(const char *data)
{
  return isLetterE(*data) && ((isNumberSign(*(data + 1)) && isUnsignedInteger2(data + 2)) || isUnsignedInteger2(data + 1));
}
bool isUnsignedInteger1(const char *data)
{
  return isDigit(*data) && (isDigit(*data) && isUnsignedInteger1(data + 1) || isBase(data + 1));
}
bool isFloat(const char *data)
{
  return !isZero(*data) && (isSignificand(data)) || (isNumberSign(*data) && isSignificand(data + 1));
}
int main()
{
  const char *testArr[] = {
    "", ".92", ".4", "4", "92", "+", "+.92", "+.4", "+4",
    "+92",
    "E+92", ".92E+92", ".4E+92", "4E+92", "92E+92", "+E+92", "+.92E+92", "+.4E+92", "+4E+92", "+92E+92", "E+4",
    ".92E+4", ".4E+4",
    "4E+4",
    "92E+4",
    "+E+4", "+.92E+4", "+.4E+4", "+4E+4", "+92E+4", "E4", ".92E4", ".4E4",
    "4E4",
    "92E4", "+E4", "+.92E4", "+.4E4", "+4E4", "+92E4", "E92", ".92E92", ".4E92", "4E92",
    "92E92", "+E92", "+.92E92", "+.4E92", "+4E92",
    "+92E92",
  };
  for (auto test: testArr)
  {
    if(!isFloat(test)) std::cout << isFloat(test) << " " << test << "\n";
  }
}
