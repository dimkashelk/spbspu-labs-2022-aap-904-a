#include <iostream>
#include "secondmax.hpp"
#include "maxsame.hpp"

int main() {
  SecondMax sec_max{0};
  MaxSameCounter max_same_cnt{0};
  int curr_value = 0;

  do
  {
    std::cin >> curr_value;
    if (!std::cin)
    {
      std::cerr << "You didn't enter an integer number\n";
      return 1;
    }
    try
    {
      sec_max(curr_value);
      max_same_cnt(curr_value);
    }
    catch (const std::overflow_error & e)
    {
      std::cout << "Error happened: ";
      std::cout << e.what() << "\n";
      return 1;
    }
  }
  while (curr_value && std::cin);
  std::cout << sec_max.second_max << " " << max_same_cnt.max_same_count << "\n";
  return 0;
}
