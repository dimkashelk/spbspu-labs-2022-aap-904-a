#include <iostream>
#include "max.seq.cnt.h"
#include "cnt.prev.devisor.h"

int main()
{
  MaxSeqRow max_sr{1};
  CntDevPrev cnt_dev{0};
  int value = 0;
  int previous_val = 0;

  do
  {
     std::cin >> value;
     try
     {
       max_sr(value, previous_val);
       cnt_dev(value, previous_val);
     }
     catch (const std::overflow_error& e)
     {
       std::cout << e.what() << "\n";
       return 1;
     }
        previous_val = value;

   } 
   while (value && std::cin);
   {
     if (!std::cin)
     {
       std::cout << "You've entered something wrong.....";
       return 2;
     }
     std::cout << "Maximum equal elements in the row: " << max_sr.max_seq_row << "\n";
     std::cout << "Number of elements which have good devisor: " << cnt_dev.cnt_devisor_counter << "\n";
     return 0;
   }
}
