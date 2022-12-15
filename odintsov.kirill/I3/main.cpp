#include <iostream>
#include <stdexcept>
#include "cstr.hpp"

int main()
{
  const size_t cap = 10;
  odintsov::CString cstr(cap);
  std::cin >> std::noskipws;
  try {
    char c = '\0';
    do {
      std::cin >> c;
      if (!std::cin) {
        std::cout << "Error: Input error\n";
        return 1;
      }
      if (c == '\n') {
        break;
      }
      cstr.append(c);
    } while (std::cin && c != '\n');
  } catch (const std::invalid_argument& err) {
    std::cout << err.what() << '\n';
    return 1;
  }
  std::cout << cstr.str << '\n';
}
