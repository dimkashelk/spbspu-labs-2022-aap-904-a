#include <iostream>
#include <cstring>
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"
#include <limits>
int main() {
    const int MAX_LENGTH = 100;
    char str[MAX_LENGTH];
    std::cin.getline(str, MAX_LENGTH);

    size_t size1 = removeDuplicateSpaces(str, str);
    if (size1 == std::numeric_limits<size_t>::max()) {
        std::cerr << "Error: removeDuplicateSpaces failed" << '\n';
        return 1;
    }

    char res2[MAX_LENGTH];
    size_t size2 = removeDigits(res2, str);
    if (size2 == std::numeric_limits<size_t>::max()) {
        std::cerr << "Error: removeDigits failed" << '\n';
        return 2;
    }

    std::cout << res2 << '\n';
    return 0;
}
