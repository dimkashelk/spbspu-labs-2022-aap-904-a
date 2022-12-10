#include <iostream>
#include "sequence_interaction.h"
#include "sequence_max.h"

int main()
{
  int n = 0;
  Lab_I1 sequence1;
  Lab_I1_T2 sequence2;
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
     try
     {
       sequence1(n);
       sequence2(n);
     }
     catch (const std::runtime_error& e)
     {
       std::cerr << e.what() << '\n';
       return 1;
     }
   }
  }
  while (n != 0);
  std::cout << sequence1.get_count() << " elements of this sequence are smaller than the previous element, but larger than the next one.\n";
  std::cout << sequence2.get_count_after_max() << " elements of this sequence are placed after the maximum element.\n";
  return 0;
}
