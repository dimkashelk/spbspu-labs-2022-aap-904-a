#include <iostream>
#include "MaxSeqLen.hpp"
#include "MinCount.hpp"

int main()
{
  MaxSeqLen seq_len{0, 0, 0};
  MinCount min_cnt{0, 0};
  int value = 0;
  do
  {
    std::cin >> value;
    if (std::cin)
    {
      try
      {
        seq_len(value);
        min_cnt(value);
      }
      catch (const std::overflow_error& e)
      {
        std::cout << "Error happened:\n";
        std::cout << e.what() << "\n";
        return 1;
      }
    }
    else
    {
      std::cerr << "Your input is not an integer\n";
      return 1;
    }
  }
  while (value && std::cin);

  std::cout << "Minimum numbers count: " << min_cnt.minvaluecounter << ". The minimum at: " << min_cnt.minvalue;
  std::cout << "\nMax up sequence with " << seq_len.maxupseqcount << " numbers\n";
}
