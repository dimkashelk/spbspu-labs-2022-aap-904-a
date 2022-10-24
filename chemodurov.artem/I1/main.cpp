#include "count.h"

int main()
{
  MinCounter min_cnt{0};
  MaxEvenCounter max_even_cnt{0};
  int curr_value = 0;

  do
  {
    std::cin >> curr_value;
    if (!std::cin)
    {
      std::cerr << "You didn`t enter an integer number\n";
      return 1;
    }
    try
    {
      min_cnt(curr_value);
      max_even_cnt(curr_value);
    }
    catch (const std::overflow_error & e)
    {
      std::cout << e.what() << "\n";
      return 1;
    }
  }
  while (std::cin && curr_value);

  std::cout << min_cnt.min_count << " " << max_even_cnt.max_even_count << "\n";
  return 0;
}
