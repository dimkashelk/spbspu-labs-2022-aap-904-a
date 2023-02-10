#include <iostream>
#include <cctype>
#include "removeDigits.h"
#include "removeDuplicateSpaces.h"

int main() {
    char str[100];
    std::cin.getline(str, 100);

    int size1 = removeDuplicateSpaces(str, str);
    if (static_cast<int>(size1) == -1) {
        std::cerr << "Error: Insufficient memory" << '\n';
        return 3;
    }

    char res2[100];
    int size2 = removeDigits(res2, str);
    if (static_cast<int>(size2) == -1) {
        std::cerr << "Error: Insufficient memory" << '\n';
        return 3;
    }

    std::cout << res2 << '\n';
    return 0;
}
