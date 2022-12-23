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
      if (c == '\n' || c == '\0') {
        break;
      }
      cstr.append(c);
    } while (std::cin);
    if (cstr.size <= 1) {
      std::cout << "Error: Empty string" << '\n';
      return 1;
    }
    {
      odintsov::CString cstrNoLatin(cstr.size);
      odintsov::removeLatin(cstr.str, cstrNoLatin.str);
      std::cout << cstrNoLatin.str << '\n';
    }
    {
      odintsov::CString cstrNoVowels(cstr.size);
      odintsov::removeVowels(cstr.str, cstrNoVowels.str);
      std::cout << cstrNoVowels.str << '\n';
    }
  } catch (const std::invalid_argument& err) {
    std::cout << "Error: " << err.what() << '\n';
    return 1;
  }
}
