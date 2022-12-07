#include "sequence_interaction.h"
#include <iostream>

int main()
{
  setlocale(LC_ALL, "ru");
  int n = 0;
  do {
   std::cout << "Enter number\n";
   std::cin >> n;
   if (std::cin.fail())
   {
     std::cerr << "INPUT ERROR: a number must be entered";
     return 1;
   }
   else
   {
     Lab_I1 sequence(n);
     sequence();
   }
  } while (n != 0);
  return 0;
}
