#ifndef QUANTITYSIGNCHANGE_H
#define QUANTITYSIGNCHANGE_H

class QuantitySignChange
{
public:
  unsigned int sign_change = 0;
  void operator()(const int current_val);

private:
  int prev_val = 0;
  int before_prev_val = 0;
};

#endif
