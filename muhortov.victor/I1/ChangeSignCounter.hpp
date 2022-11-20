#ifndef	CHANGESIGNCOUNTER_HPP
#define CHANGESIGNCOUNTER_HPP

struct CountSignChanges
{
  void operator()(int x, int y);
  unsigned int ChangeSignCounter;
};
#endif
