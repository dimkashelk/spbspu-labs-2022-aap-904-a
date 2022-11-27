#ifndef ELMORETHANPREV_H
#define ELMORETHANPREV_H
struct ElMoreThanPrev
{
  int prev;
  int count = 0;
  void operator()(unsigned int curr);
};
#endif
