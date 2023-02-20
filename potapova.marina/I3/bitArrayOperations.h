#ifndef BITARRAYOPERATIONS_H
#define BITARRAYOPERATIONS_H

#include <cstdint>

using BitArr256 = uint64_t[4];

void setBitToOne(BitArr256& arr, uint8_t index);
bool isSetBit(const BitArr256& arr, uint8_t index);

#endif
