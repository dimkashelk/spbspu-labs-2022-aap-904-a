#include <iostream>
#include "minelementcounter.hpp"
#include "maxincreasingsequence.hpp"
#include "minelementcounter.cpp"
#include "maxincreasingsequence.cpp"

int main()
{
  MinElementCounter min_elem_ctr{0};
  MaxIncreasingSequence max_inc_seqn{0};
  int cur_value = 0;

  do
  {
    std::cin >> cur_value;
    if (!std::cin)
    {
      std::cerr << "You didn't enter an integer number\n";
      return 1;
    }
    try
    {
      min_elem_ctr(cur_value);
      max_inc_seqn(cur_value);
    }
    catch (const std::overflow_error& e)
    {
      std::cout << "Error:" << e.what() << "\n";
      return 1;
    }
  }
  while (cur_value && std::cin);

  std::cout << min_elem_ctr.count_min << " " << max_inc_seqn.max_len_seqn << "\n";
  return 0;

}
