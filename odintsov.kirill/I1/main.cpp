#include <iostream>
#include <limits>
#include "sequence.hpp"

int main()
{
  const int minInt = std::numeric_limits< int >::min();
  odintsov::LargestCounter countLargest {minInt, 0};
  odintsov::DescendingCounter countDescending {minInt, false, 0};
  int v = 0;
  do {
    std::cin >> v;
    if (!std::cin) {
      std::cout << "Input error\n";
      return 1;
    }
    if (v == 0) {
      break;
    }
    countLargest(v);
    countDescending(v);
  } while (v != 0 && std::cin);
  std::cout << countLargest.n << ' '
            << countDescending.n << '\n';
}
