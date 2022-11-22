#ifndef SEQUENCES_H
#define SEQUENCES_H

struct Localminimals
{
  int countlocalmin = 0;
  int current = 0;
  int next = 0;
  void operator()(int previous, std::istream& in)
};

struct Minsrmax
{
  int countofsequenceelements = 0;
  int countminsrmax = 0;
  int current = 0;
  int next = 0;
  void operator()(int previous, std::istream& in)
};
#endif
