#include <iostream>
#include <limits>
#include "structure.h"

void values::operator()(int value)
{
    const int maxValue = std::numeric_limits< int >::max();
    if (maxNum == maxValue)
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
void localValuesMax::operator()(int value)
{
    const int maxLocalVal = std::numeric_limits< int >::max();
    if (nValueL == maxLocalVal)
    {
        std::cout << "overflow";
    }
    nValueL += (predVL > value && predVL > predPredVL);
    predPredVL = predVL;
    predVL = value;
}
