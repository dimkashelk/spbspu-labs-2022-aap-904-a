#ifndef EXPRESSIONPROCESSING_H
#define EXPRESSIONPROCESSING_H
#include <cstddef>
namespace turkin
{
  bool isEnd(char c);
  bool isSign(char c);
  bool isDigit(char c);
  bool isID(char c);
  bool isMultiplier(const char * array);
  bool isTerm(const char * array);
  bool isExpression(const char * array);
}
#endif
