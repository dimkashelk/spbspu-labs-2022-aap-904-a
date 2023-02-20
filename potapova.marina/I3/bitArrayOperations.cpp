#include "bitArrayOperations.h"

const uint8_t NUM_ROWS = 64;

void setBitToOne(BitArr256& arr, const uint8_t index)
{
    arr[index >> 6] |= (1 << (index & 63));
}

bool isSetBit(const BitArr256& arr, const uint8_t index)
{
    return arr[index >> 6] & (1 << (index & 63));
}
