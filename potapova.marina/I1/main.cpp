#include <iostream>

int main() {
  CounterPythagoreanTriplets pythcnt{0, 0, 0};
  CounterSignChange signchangecnt{0, 0};
  int currval = 0;

  do {
    std::cin >> currval;
    pythcnt(currval);
    signchangecnt(currval);
  } while (std::cin && currval);
  
  std::cout << pythcnt.count << "\n";
  std::cout << signchangecnt.count << "\n";
  return 0;
}
