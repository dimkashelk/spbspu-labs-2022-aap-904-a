#ifndef ISREALNUMBER_HPP
#define ISREALNUMBER_HPP

namespace detail {
  const char* skipUnsigned(const char* string);
  const char* skipExponent(const char* string);
  const char* skipMantissa(const char* string);
  const char* skipSign(const char* string);
  const char* skipRealNumber(const char* string);
}

namespace odintsov {
  bool isRealNumber(const char* string);
}

#endif
