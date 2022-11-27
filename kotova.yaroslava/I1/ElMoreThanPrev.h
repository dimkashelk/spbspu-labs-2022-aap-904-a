#ifndef ELMORETHANPREV_H
#define ELMORETHANPREV_H
struct ElMoreThanPrev
{
  int prev;
  int unsigned count = 0;
  void operator()(int curr);
};
#endif
