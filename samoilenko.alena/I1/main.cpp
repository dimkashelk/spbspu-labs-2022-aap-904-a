#include "LenghthSame.h"
#include <iostream>
#include "LenghthDecr.h"
int main() {
    int maxLenghthSame = 0;
    int lenghthSame = 1;
    int maxLenghthDecr = 0;
    int lenghthDecr = 1;
    int predV = 0;
    int value = 0;

    do {
        std::cin >> value;
        lenghthSame = lenghthSameF (predV, value, lenghthSame);
        if (lenghthSame > maxLenghthSame) {
            maxLenghthSame = lenghthSame;
        }

        lenghthDecr = lenghthDecrF (predV, value, lenghthDecr);
        if (lenghthDecr > maxLenghthDecr) {
            maxLenghthDecr = lenghthDecr;
        }

        predV = value;
    }
    while (value && std::cin);
    std::cout << maxLenghthDecr << "\n";
    std::cout << maxLenghthSame << "\n";
}