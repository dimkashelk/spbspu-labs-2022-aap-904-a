#include "isFloat.h"
#include <cctype>
bool continueWithDigit(const char *symbol);
bool continueWithSign(const char *symbol);
bool continueWihtPoint(const char *symbol);
bool continueWithE(const char *symbol);
bool continueFirstDigitPart(const char *symbol);
bool continueSecondDigitPart(const char *symbol);
bool isDigit(char symbol)
{
  return std::isdigit(symbol);
}
bool isSign(char symbol)
{
  return (symbol == '+' || symbol == '-');
}
bool isPoint(char symbol)
{
  return (symbol == '.');
}
bool isEnd(char symbol)
{
  return (symbol == '\0');
}
bool isE(char symbol)
{
  return (symbol == 'E');
}

bool continueWithDigit(const char *symbol)
{
 return isDigit(*symbol) && (continueWithDigit(symbol + 1) || continueWithE(symbol + 1) || continueWithDot(symbol + 1));
}
bool continueWithSign(const char *symbol)
{
  return isSign(*symbol) && continueSecondDigitPart(symbol + 1);
}
bool continueWihtPoint(const char *symbol)
{
  return isPoint(*symbol) && continueFirstDigitPart(symbol + 1);
}
bool continueWithE(const char *symbol)
{
  return isE(*symbol) && continueSecondDigitPart(symbol + 1);
}
bool continueFirstDigitPart(const char *symbol)
{
  return isDigit(*symbol) && (continueFirstDigitPart(symbol + 1) || continueWithE(symbol + 1));
}
bool continueSecondDigitPart(const char *symbol)
{
  return isDigit(*symbol) && (continueSecondDigitPart(symbol + 1) || isEnd(*(symbol + 1)));
}
bool isFloat(const char *expr)
{
  bool firstOption = isSign(*symbol) && continueWithDigit(symbol + 1);
  bool secondOption = isDigit(*symbol) && (continueWithDigit(symbol + 1) || continueWithE(symbol + 1) || continueWithPoint(symbol + 1));
  return firstOption || secondOption;
}
