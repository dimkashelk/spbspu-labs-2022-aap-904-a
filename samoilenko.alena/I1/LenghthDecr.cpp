#include "LenghthDecr.h"

int lenghthDecrF (int pred, int curr, int lenghth) {
    if (pred > curr && curr != 0 && pred != 0) {
        return lenghth += 1;
    }
    else {
        return 1;
    }
}
