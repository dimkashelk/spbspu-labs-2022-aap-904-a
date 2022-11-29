#ifndef CNT_PREV_DEVISOR_H
#define CNT_PREV_DEVISOR_H

struct CntDevPrev
{
  void operator()(int value);
  
  unsigned int cnt_devisor_counter;
  int devisor_func_value;
  int devisor_func_previous_value;
};
#endif
