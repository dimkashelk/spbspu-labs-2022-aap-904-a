#ifndef DIVNOREMAINDER_H
#define DIVNOREMAINDER_H

struct DivNoRemainder
{
  unsigned int getRezult() const;

  void operator()(int current);
private:
  int previous = 0;
  unsigned int quantity = 0;
};

#endif
