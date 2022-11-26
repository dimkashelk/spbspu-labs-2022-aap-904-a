#include <iostream>
#include "amountofmin.hpp"

void Znach::operator()(int value)
{
  if (min == 0)
  {
    min = value;
  }
  if (min != 0 && value < min && value != 0)
  {
    min = value;
    counter = 0;
  }
  if (min == value )
  {
    if (counter == MaxDlyIskl)
    {
      //std::cout << counter;
      //std::cout << MaxDlyIskl;
      std::cout << "OverFlow \n";
    }
    else
    {
       counter++;
      // std::cout << counter;
    }
  }
}
