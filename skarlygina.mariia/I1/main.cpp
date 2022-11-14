#include "supplement.h"
#include <iostream>;

int main()
{
  int value = 0;
  int k = 0;
  MaxSameValue max_same_value{0};
  MaxGrowingSequence max_growing_sequence{0};
  do
  {
    std::cin >> value;
    if (!std::cin)
    {
      std::cout << "Error, value is not a number";
      return 1;
    }
    max_same_value(value);
    max_growing_sequence(value);
		
    if (value == 0)
    {	
      std::cout << "Max number of same value " << max_same_value.max_number_of_same_value << "\n";
      std::cout << "Max number of growing sequence " <<max_growing_sequence.max_number_of_growing_sequence << "\n";
      return 1;
    }
  }
  while (std::cin && value);
  return 0;
}
