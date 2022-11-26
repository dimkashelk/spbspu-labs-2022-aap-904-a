#include <iostream>
#include "amountofavr.hpp"

void Family::operator()(int value)
{
  dite = value;
  //std::cout << "Введёное число" << dite << "\n";
  if (papa > ded && dite > papa)
  {
    if (counter1 >= MaxDlyIskl2)
    {
      std::cout << "OverFlow \n";
    }
    else
    {
    counter1++;
    //std::cout << "кол-во сейчас " << counter1 << "\n";
    }
  }
  else
  {
    ded = papa;
    //std::cout << "Дед " << ded << "\n";
    papa = dite;
  }
}
