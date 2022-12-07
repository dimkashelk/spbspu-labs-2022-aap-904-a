#include "sequence_interaction.h"
#include <iostream>

int Lab_I1::max_n{ 0 };
int Lab_I1::old_n{ 0 };
int Lab_I1::cur_n{ 0 };
int Lab_I1::new_n{ 0 };
int Lab_I1::count{ 0 };
int Lab_I1::count_after_max{ 0 };

Lab_I1::Lab_I1(int n) :
 n(n)
{}

void Lab_I1::operator()()
{
  if (n == 0)
  {
    conclusion();
  }
  else
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
}

void Lab_I1::conclusion()
{
  std::cout << count << " elements of this sequence are smaller than the previous element, but larger than the next one.\n";
  std::cout << count_after_max << " elements of this sequence are placed after the maximum element.\n";
}
