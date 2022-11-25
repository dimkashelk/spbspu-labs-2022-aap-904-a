#ifndef SEQUENCES_H
#define SEQUENCES_H

struct Localminimals
{
  Localminimals();
  unsigned int countlocalmin = 0;
  int current = 0;
  int next = 0;
  void operator()(int previous);
};

struct Minsrmax
{
  Minsrmax();
  unsigned int countofsequenceelements = 0;
  unsigned int countminsrmax = 0;
  int current = 0;
  int next = 0;
  void operator()(int previous);
};
#endif
