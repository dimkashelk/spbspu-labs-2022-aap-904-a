#include <iostream>
#include "counters.h"
#include <stdexcept>

int main() {
  dividendCounter DivCnt{0, 0};
  equalToSumCounter EqCnt{0, {200, 144}};
  int value = 0;
  std::cin >> value;

  try {
    while (value && std::cin) {
      DivCnt(value);
      EqCnt(value);
      std::cin >> value;
    }

    if (!std::cin) {
      throw std::runtime_error("Something happened to the input stream, sry(\n");
    }
    std::cout << "Numbers that are dividends of prevs count: " << DivCnt.cnt << '\n';
    std::cout << "Numbers that are a sum of two prevs count: " << EqCnt.cnt << '\n';
  }


  catch(std::overflow_error & err) {
    std::cout << "Error: " << err.what() << "\n";
  }
  catch(std::runtime_error & err) {
    std::cout << "Error: " << err.what() << '\n';
  }
}
