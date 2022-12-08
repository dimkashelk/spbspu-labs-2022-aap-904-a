#include <iostream>
#include "sequence_interaction.h"

int main()
{
  int n = 0;
  Lab_I1 sequence;
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
       sequence(n);
     }
     catch(const std::runtime_error& e)
     {
       std::cerr << e.what() << '\n';
       return 1;
     }
   }
  }
  while (n != 0);
  std::cout << sequence.get_count() << " elements of this sequence are smaller than the previous element, but larger than the next one.\n";
  std::cout << sequence.get_count_after_max() << " elements of this sequence are placed after the maximum element.\n";
  return 0;
}
