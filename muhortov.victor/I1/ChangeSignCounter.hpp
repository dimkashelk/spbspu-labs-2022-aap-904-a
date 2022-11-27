#ifndef CHANGESIGNCOUNTER_HPP
#define CHANGESIGNCOUNTER_HPP

struct CountSignChanges
{
  void operator()(int x);
  unsigned int ChangeSignCounter;
  int y;
};
#endif
