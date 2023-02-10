#include <iostream>
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"

int main() {
    char str[100];
    std::cin.getline(str, 100);

    char res1[100];
    size_t size1 = removeDuplicateSpaces(res1, str);
    if (size1 != static_cast<size_t>(-1)) {
        std::cout << res1 << '\n';
    } else {
        std::cerr << "Memory allocation failed for `res1`" << '\n';
    }

    char res2[27];
    size_t size2 = removeDigits(res2, str);
    if (size2 != static_cast<size_t>(-1)) {
        std::cout << res2 << '\n';
    } else {
        std::cerr << "Memory allocation failed for `res2`" << '\n';
    }
    return 0;
}
