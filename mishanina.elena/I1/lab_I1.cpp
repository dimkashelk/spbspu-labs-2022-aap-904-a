#include "sequence_interaction.h"
#include <iostream>

int main()
{
  setlocale(LC_ALL, "ru");
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
   else if (n == 0)
   {
     std::cout << sequence.get_count() << " elements of this sequence are smaller than the previous element, but larger than the next one.\n";
     std::cout << sequence.get_count_after_max() << " elements of this sequence are placed after the maximum element.\n";
   }
   else
   {
     sequence(n);
   }
  } while (n != 0);
  return 0;
}
