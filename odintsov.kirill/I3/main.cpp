#include <iostream>
#include <stdexcept>
#include "cstr.hpp"

int main()
{
  constexpr size_t cap = 10;
  odintsov::CString cstr(cap);
  std::cin >> std::noskipws;
  try {
    char c = '\0';
    do {
      std::cin >> c;
      if (!std::cin.good()) {
        std::cout << "Error: Input error\n";
        return 1;
      }
      if (c == '\n') {
        break;
      }
      cstr.append(c);
    } while (std::cin.good() && c != '\n');
    {
      odintsov::CString cstrNoLatin(cap);
      odintsov::removeLatin(cstr, cstrNoLatin);
      std::cout << cstrNoLatin.str << '\n';
    }
    {
      odintsov::CString cstrNoVowels(cap);
      odintsov::removeVowels(cstr, cstrNoVowels);
      std::cout << cstrNoVowels.str << '\n';
    }
  } catch (const std::invalid_argument& err) {
    std::cout << "Error: " << err.what() << '\n';
    return 1;
  }
}
