#ifndef QUANTITYLOCALMIN_H
#define QUANTITYLOCALMIN_H

class QuantityLocalMin
{
public:
  unsigned int local_min = 0;
  void operator()(const int current_val);

private:
  int prev_val = 0;
  int before_prev_val = 0;
};

#endif
