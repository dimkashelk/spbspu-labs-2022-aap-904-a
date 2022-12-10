#include "sequence_max.h"

Lab_I1_T2::Lab_I1_T2():
 n(0),
 max_n(0),
 count_after_max(0)
{}

void Lab_I1_T2::operator()(int n)
{
  if (max_n < n)
  {
    count_after_max = 0;
    max_n = n;
  }
  else
  {
    count_after_max++;
  }
}

int Lab_I1_T2::get_count_after_max() const
{
  return count_after_max;
}
