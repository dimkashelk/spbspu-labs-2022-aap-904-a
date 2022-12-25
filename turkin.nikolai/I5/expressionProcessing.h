#ifndef EXPRESSIONPROCESSING_H
#define EXPRESSIONPROCESSING_H
#include <charArray.h>
namespace turkin
{
  bool isEnd(char c);
  bool isSign(char c);
  bool isDigit(char c);
  bool isID(char c);
  bool isMultiplier(const turkin::CharArray & array, size_t i);
  bool isTerm(const turkin::CharArray & array, size_t i);
  bool isExpression(const turkin::CharArray & array, size_t i);
}
#endif
