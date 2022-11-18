#ifndef SUPPLEMENT_GROWING_H
#define SUPPLEMENT_GROWING_H

struct MaxGrowingSequence
{
  void operator()(int value);
  int value_before = 0;
  unsigned int number_of_growing_sequence = 0;
  unsigned int max_number_of_growing_sequence = 0;
};

#endif