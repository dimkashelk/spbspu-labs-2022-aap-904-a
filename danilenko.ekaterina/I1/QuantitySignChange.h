#ifndef QUANTITYSIGNCHANGE_H
#define QUANTITYSIGNCHANGE_H

class QuantitySignChange
{
public:
  unsigned int sign_change = 0;
  void operator()(const int current_val, const int prev_val);
};

#endif
