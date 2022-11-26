#ifndef SEQUENCES_H
#define SEQUENCES_H

struct Localminimals
{
  Localminimals(int prev);
  unsigned int count;
  int current;
  int next;
  void operator()(int previous);
  unsigned int totalcount() const;
};

struct Minsrmax
{
  Minsrmax(int prev);
  unsigned int countofsequenceelements;
  unsigned int count;
  int current;
  int next;
  void operator()(int previous);
  unsigned int totalcount() const;
};
#endif
