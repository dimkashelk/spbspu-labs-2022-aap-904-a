#include "QuantityLocalMin.h"
#include "QuantitySignChange.h"
#include <iostream>
#include <limits>

int main()
{
  int current_val = 0;
  QuantityLocalMin LocalMin;
  QuantitySignChange SignChange;

  do
  {
    std::cin >> current_val;
    if (!std::cin)
    {
      std::cout << "Incorrect input" << "\n";
      break;
    }
    if (current_val == 0)
    {
      break;
    }

    try
    {
      SignChange(current_val);
      LocalMin(current_val);
    }
    catch (const std::overflow_error & e)
    {
      std::cout << "Error..." << "\n";
      std::cout << e.what() << "\n";
      return 1;
    }
  }
  while (std::cin && current_val);

  std::cout << "Number of local min: " << LocalMin.local_min << "\n";
  std::cout << "Number of sign changed: " << SignChange.sign_change << "\n";
}
