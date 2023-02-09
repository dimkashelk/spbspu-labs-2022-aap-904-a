#include <iostream>
#include <fstream>
#include "removeDuplicateSpaces.h"
#include "removeDigits.h"

int main() {
    std::string str;
    std::getline(std::cin, str);

    try {
        std::string res1 = str;
        removeDuplicateSpaces(&res1[0], &res1[0]);
        std::cout << res1 << '\n';
    } catch (const std::bad_alloc &e) {
        std::cerr << "Few memory" << '\n' << e.what();
        return 3;
    }

    try {
        char res2[27];
        removeDigits(res2, str.c_str());
        std::cout << res2 << '\n';
    } catch (const std::bad_alloc &e) {
        std::cerr << "Few memory" << '\n' << e.what();
        return 3;
    }
    return 0;
}
