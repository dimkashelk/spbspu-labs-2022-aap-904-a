#include <iostream>
#include <limits>
#include "structure.h"

void values::operator()(int value)
{
    const int max_unsigned_value = std::numeric_limits< unsigned int >::max();
    if (maxNum == max_unsigned_value)
    {
        std::cout << "overflow";
    }
    else if (value == predV)
    {
        nValue += 1;
    }
    else
    {
        maxNum = std::max(nValue, maxNum);
        nValue = 1;
    }
    predV = value;
}