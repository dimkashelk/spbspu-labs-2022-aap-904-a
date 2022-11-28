#ifndef DIVNOREMAINDER_H
#define DIVNOREMAINDER_H

struct DivNoRemainder
{
public:
  unsigned int quantity = 0;

  void operator()(int current);
private:
  int previous = 0;
};

#endif
