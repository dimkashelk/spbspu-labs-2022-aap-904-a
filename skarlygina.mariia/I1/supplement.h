#ifndef SUPPLEMENT_H
#define SUPPLEMENT_H

struct MaxSameValue
{
  unsigned int number_of_same_value = 0;
  unsigned int max_number_of_same_value = 0;
  void operator()(int value);
  int value_before = 0;
};

struct MaxGrowingSequence
{
  unsigned int number_of_growing_sequence = 0;
  unsigned int max_number_of_growing_sequence = 0;
  void operator()(int value);
  int value_before = 0;
};
#endif
