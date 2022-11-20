#ifndef SEQUENCES_H
#define SEQUENCES_H

struct MaxCounter
{
  int max;
  int count_max;

  void operator()(const int current_value);
};

struct MinCounter
{
  int min;
  int count_min;

  void operator()(const int current_value);
};

#endif
