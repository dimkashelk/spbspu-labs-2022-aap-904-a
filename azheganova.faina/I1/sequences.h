#ifndef SEQUENCES_H
#define SEQUENCES_H

struct Localminimals
{
  int countlocalmin = 0;
  int current = 0;
  int next = 0;
  void operator()(const int previous)
};

struct Minsrmax
{
  int countofsequenceelements = 0;
  int countminsrmax = 0;
  int current = 0;
  int next = 0;
  void operator()(const int previous)
};
#endif
