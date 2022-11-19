#ifndef SUPPLEMENT_SAME_VALUE_H
#define SUPPLEMENT_SAME_VALUE_H

struct MaxSameValue
{
  int value_before = 0;
  unsigned int number_of_same_value = 0;
  unsigned int max_number_of_same_value = 0;
  void operator()(int value);
};

#endif
