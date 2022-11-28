#ifndef SEQUENCES_H
#define SEQUENCES_H
struct values
{
  int predV = 0;
  int nValue = 0;
  int maxNum = 0;
  void operator()(int value);
};
struct localValuesMax
{
  int p_value = 0;
  int pp_value = 0;
  int count = 0;
  void operator()(int currentValue);
};
#endif
