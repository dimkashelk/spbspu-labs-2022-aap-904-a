#ifndef SEQUENCE_H
#define SEQUENCE_H
struct CounterPythagoreanTriplets {
  void operator()(int currval);
  int predval;
  int predpredval;
  int count;
};

struct CounterSignChange {
  void operator()(int currval);
  int predval;
  int count;
};
#endif
