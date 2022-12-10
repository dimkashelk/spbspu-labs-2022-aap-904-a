#include <iostream>
#include "sequence_interaction.h"
#include "sequence_max.h"

int main()
{
  int num = 0;
  Suitable_seq sequence1;
  Seq_after_max sequence2;
  if (std::cin.fail())
  {
    std::cerr << "INPUT ERROR: a number must be entered";
    return 1;
  }
  else
  {
    do {
     std::cout << "Enter number\n";
     std::cin >> num;
     try
     {
       sequence1(num);
       sequence2(num);
     }
     catch (const std::runtime_error& e)
     {
       std::cerr << e.what() << '\n';
       return 1;
     }
    }
    while (num != 0);
    std::cout << sequence1.get_count_of_elements() << " elements of this sequence are smaller than the previous element, but larger than the next one.\n";
    std::cout << sequence2.get_count_after_max() << " elements of this sequence are placed after the maximum element.\n";
    return 0;
  }
}
