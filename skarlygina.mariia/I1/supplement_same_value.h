#ifndef SUPPLEMENT_SAME_VALUE_H
#define SUPPLEMENT_SAME_VALUE_H

struct MaxSameValue
{
  void operator()(int value);
  int value_before = 0;
  unsigned int number_of_same_value = 0;
  unsigned int max_number_of_same_value = 0;
};

#endif