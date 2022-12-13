#include <iostream>
#include <stdexcept>
#include "counters.h"

int main() {
  dividendCounter DivCnt{0, 0};
  equalToSumCounter EqCnt{0, {0, 0}};
  int value = 0;
  std::cin >> value;

  try {
    while (value && std::cin) {
      DivCnt(value);
      EqCnt(value);
      std::cin >> value;
    }
  }
  catch (const std::overflow_error & err) {
    std::cout << "Error: " << err.what() << '\n';
    return 1;
  }
  if (!std::cin) {
    std::cerr << "Error: something's up with the stream, sry...";
    return 1;
  }

  std::cout << "Numbers that are dividends of prevs count: " << DivCnt.cnt << '\n';
  std::cout << "Numbers that are a sum of two prevs count: " << EqCnt.cnt << '\n';
}
