#include <iostream>
#include "sequence_interaction.h"

void Lab_I1::operator()()
{
  while (true)
  {
    std::cout << "Enter number\n";
	std::cin >> n;
	if (!std::cin) 
    {
      std::cout << "INPUT ERROR: a number must be entered";
      break;
    }

    if (n == 0) 
    {
      conclusion();
      break;
    }

    else
    {
      if (max_n < n)
      {
        max_n = n;
        count_after_max = 0;
      }
      else
        count_after_max++;

      if (old_n == 0)
        old_n = n;
      else if (cur_n == 0)
        cur_n = n;
      else
      {
        new_n = n;
        if (cur_n < old_n && cur_n > new_n)
          count++;
        old_n = cur_n;
        cur_n = new_n;
      }
    }
  }
}

void Lab_I1::conclusion()
{
  std::cout << count << " elements of this sequence are smaller than the previous element, but larger than the next one.\n";
  std::cout << count_after_max << " elements of this sequence are placed after the maximum element.\n";
}
