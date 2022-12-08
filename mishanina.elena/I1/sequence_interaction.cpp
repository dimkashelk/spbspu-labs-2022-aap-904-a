#include "sequence_interaction.h"

Lab_I1::Lab_I1()
{
  old_n = 0;
  cur_n = 0;
  new_n = 0;
  count = 0;
  max_n = 0;
  count_after_max = 0;
}

void Lab_I1::operator()(int n)
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
  if (old_n == 0)
  {
    old_n = n;
  }
  else if (cur_n == 0)
  {
    cur_n = n;
  }
  else
  {
    new_n = n;
    if (cur_n < old_n && cur_n > new_n)
    {
      count++;
    }
    old_n = cur_n;
    cur_n = new_n;
  }
}

int Lab_I1::get_count() const
{
  return count;
}

int Lab_I1::get_count_after_max() const
{
  return count_after_max;
}
