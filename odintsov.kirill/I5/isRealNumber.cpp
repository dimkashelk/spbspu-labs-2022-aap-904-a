#include "isRealNumber.hpp"
#include <cctype>

const char* detail::skipUnsigned(const char* string)
{
  if (!isdigit(*(string++))) {
    return nullptr;
  }
  return isdigit(*string) ? skipUnsigned(string) : string;
}

const char* detail::skipExponent(const char* string)
{
  if (string == nullptr || *(string++) != 'E') {
    return nullptr;
  }
  return skipUnsigned(skipSign(string));
}

const char* detail::skipMantissa(const char* string)
{
  string = skipUnsigned(string);
  if (string == nullptr || *string != '.') {
    return nullptr;
  }
  return skipUnsigned(string + 1);
}

const char* detail::skipSign(const char* string)
{
  if (*string == '+' || *string == '-') {
    return string + 1;
  }
  return string;
}

const char* detail::skipRealNumber(const char* string)
{
  return skipExponent(skipMantissa(skipSign(string)));
}

bool odintsov::isRealNumber(const char* string)
{
  string = detail::skipRealNumber(string);
  if (string == nullptr) {
    return false;
  }
  return *string == '\0';
}
