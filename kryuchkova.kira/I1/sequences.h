#ifndef SEQUENCES_H
#define SEQUENCES_H

struct MaxCounter
{
  int max;
  int count_max;

  MaxCounter();
  void operator()(const int current_value);
};

struct MinCounter
{
  int min;
  int count_min;

  MinCounter();
  void operator()(const int current_value);
};

#endif
