#include "amountofavr.hpp"
#include "amountofmin.hpp"
#include <iostream>

int main()
{
  Znach zn;
  Family fa;
  int value = 0;

  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cerr << "Error incorrect input \n";
    }
    else
    {
      zn(value);
      fa(value);
    }
  }
  while (value && std::cin);
  std::cout << "Amount of number equal to minimum :" << zn.counter << "\n";
  std::cout << "Amount of number more than prev and less than next :" << fa.counter1;
}
