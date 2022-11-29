#ifndef QUANTITYSIGNCHANGE_H
#define QUANTITYSIGNCHANGE_H

struct QuantitySignChange
{
  unsigned int sign_change = 0;
  void operator()(const int current_val);
  int prev_val = 0;
  int before_prev_val = 0;
};

#endif
