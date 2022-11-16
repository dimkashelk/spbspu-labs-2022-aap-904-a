#ifndef I1_SEQUENCE_H
#define I1_SEQUENCE_H

struct Counter {
  void operator()(int currentValue);

  unsigned long long count;
  unsigned long long countMax;

  unsigned long long previousValue;
};

struct LocalMax {
  void operator()(int currentValue);

  unsigned long long previousValue;
  unsigned long long beforePreviousValue;

  unsigned long long count;
};

#endif
