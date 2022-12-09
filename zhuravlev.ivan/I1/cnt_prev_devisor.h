#ifndef CNT_PREV_DEVISOR_H
#define CNT_PREV_DEVISOR_H

struct CntDevPrev
{
  void operator()(int value);

  unsigned int cnt_dev;
  int dev_func_val;
  int dev_func_prev_val;
};
#endif
