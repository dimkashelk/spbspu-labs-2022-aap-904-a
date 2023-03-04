#include "functions.h"
#include <iostream>

bool isSign(char data)
{
  return ((data == '+') || (data == '-'));
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

bool continuesWithDigit(const char* data)
{
  return (isDigit(*data) && continuesWithDigit(data + 1)) || isDigit(*data);
}

bool continuesWithE(const char* data)
{
  return isE(*data) && ((isSign(*(data + 1)) && continuesWithDigit(data + 2)) || continuesWithDigit(data + 1));
}

bool continuesWithDot(const char* data)
{
  return isDot(*(data)) && continuesWithDigit(data + 1);
}

bool continuesWithM(const char* data)
{
  return continuesWithDigit(data) && continuesWithDot(data + 1);
}

bool isFloat(const char* data)
{
  return (continuesWithM(data) && continuesWithE(data + 1)) || (isSign(*data) && continuesWithM(data + 1) && continuesWithE(data + 2));
}
