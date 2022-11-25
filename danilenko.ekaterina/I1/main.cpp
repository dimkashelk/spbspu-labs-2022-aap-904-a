#include "QuantityLocalMin.h"
#include "QuantitySignChange.h"
#include <iostream>
#include <limits>

int main()
{
  int current_val = 0;
  int prev_val = 0;
  int before_prev_val = 0;
  QuantityLocalMin LocalMin;
  QuantitySignChange SignChange;

  do
  {
    std::cin >> current_val;
    if (!std::cin)
    {
      std::cout << "Incorrect input" << std::endl;
      break;
    }
    if (current_val == 0)
    {
      break;
    }

    try
    {
      SignChange(current_val, prev_val);
      LocalMin(current_val, prev_val, before_prev_val);
    }
    catch (std::overflow_error& e)
    {
      std::cout << "Error..." << std::endl;
      std::cout << e.what() << std::endl;
      return 1;
    }

    before_prev_val = prev_val;
    prev_val = current_val;
  }
  while (std::cin && current_val);

  std::cout << "Number of local min: " << LocalMin.local_min << std::endl;
  std::cout << "Number of sign changed: " << SignChange.sign_change << std::endl;
}
