#include "CountLarge.h"
#include "LengthEvenCount.h"
#include <iostream>
#include <limits>

int main()
{
  int curr_val = 0;
  CountLarg count_larg{ 0 };
  LenEvenCounter len_even_count{ 0 };

  do
  {
    std::cin >> curr_val;
    if (!std::cin)
    {
      std::cout << "Invailed Input" << "\n";
      return 1;
    }
    if (curr_val == 0)
    {
      break;
    }
    try
    {
      count_larg(curr_val);
      len_even_count(curr_val);
    }
    catch (const std::overflow_error& e)
    {
      std::cout << e.what() << '\n';
      return 1;
    }
  } while (curr_val != 0 && std::cin);

  std::cout << "amount of elements: " << count_larg.count_amount << '\n';
  std::cout << "length even elements: " << len_even_count.count_len_even << "\n";
}