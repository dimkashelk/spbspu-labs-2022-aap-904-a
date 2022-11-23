#include "countelaftermaxel.h"
#include <stdexcept>
#include <limits>

void СountElAfterMaxEl::operator()(int el)
{
    const unsigned int maxInt = std::numeric_limits< unsigned >::max();
    if (el)
    {
        if (el < max)
        {
            if (count == maxInt)
            {
                throw std::overflow_error("Overflow\n");
            }
            else
            {
                count++;
            }
        }
        else
        {
            max = el;
            count = 0;
        }
    }
}

