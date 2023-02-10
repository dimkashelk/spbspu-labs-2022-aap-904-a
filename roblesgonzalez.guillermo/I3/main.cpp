#include <iostream>
#include <fstream>
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"

int main() {
    std::string str;
    if (!std::getline(std::cin, str)) {
        std::cerr << "Error: no input provided" << '\n';
        return 1;
    }

    try {
        char res1[100];
        int size1 = removeDuplicateSpaces(res1, str.c_str());
        if (size1 == -1) {
            std::cerr << "Error: not enough memory" << '\n';
            return 2;
        }
        std::cout << res1 << '\n';
    } catch (const std::bad_alloc &e) {
        std::cerr << "Error: not enough memory" << '\n' << e.what();
        return 2;
    }

    try {
        char res2[27];
        int size2 = removeDigits(res2, str.c_str());
        if (size2 == -1) {
            std::cerr << "Error: not enough memory" << '\n';
            return 2;
        }
        std::cout << res2 << '\n';
    } catch (const std::bad_alloc &e) {
        std::cerr << "Error: not enough memory" << '\n' << e.what();
        return 2;
    }
    return 0;
}
