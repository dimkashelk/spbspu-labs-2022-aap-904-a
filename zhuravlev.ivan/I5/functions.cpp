#include "functions.h"
#include <iostream>

bool isSign(char data)
{
  return (data == '+') || (data == '-');
}
bool isDigit(char data)
{
  return std::isdigit(data);
}
bool isE(char data)
{
  return data == 'E';
}
bool isDot(char data)
{
  return (data == '.');
}
bool End(const char* data)
{
  return (isDigit(*data) && (End(data + 1) || *(data + 1) == '\0'));
}
bool ifE(const char* data)
{
  return (isE(*data) && ((isSign(*(data + 1)) && End(data + 2)) || End(data + 1)));
}
bool continueWithDigitAfterDot(const char* data)
{
  return (isDigit(*data) || ifE(data + 1));
}
bool ifDot(const char* data)
{
  return (isDot(*data) && continueWithDigitAfterDot(data + 1));
}
bool continueWithDigit(const char* data)
{
  return ((isDigit(*data) && continueWithDigit(data + 1))|| ifDot(data));
}

bool isFloat(const char* data)
{
  return  (continueWithDigit(data) || (isSign(*data) && continueWithDigit((data + 1))));
}
