#ifndef SUPPLEMENT_GROWING_SEQUENCE_H
#define SUPPLEMENT_GROWING_SEQUENCE_H

struct MaxGrowingSequence
{
  int value_before = 0;
  unsigned int number_of_growing_sequence = 0;
  unsigned int max_number_of_growing_sequence = 0;
  void operator()(int value);
};

#endif

