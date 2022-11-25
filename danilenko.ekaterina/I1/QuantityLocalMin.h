#ifndef QUANTITYLOCALMIN_H
#define QUANTITYLOCALMIN_H

class QuantityLocalMin
{
public:
  unsigned int local_min = 0;
  void operator()(const int current_val, const int prev_val, const int before_prev_val);
};

#endif
