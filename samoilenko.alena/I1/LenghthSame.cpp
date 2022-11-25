#include "LenghthSame.h"

int lenghthSameF (int pred, int curr, int lenghth) {
    if (pred == curr && curr != 0) {
        return lenghth += 1;
    }
    else {
        return 1;
    }
}
