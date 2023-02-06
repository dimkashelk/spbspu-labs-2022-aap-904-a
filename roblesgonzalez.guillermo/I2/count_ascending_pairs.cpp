#include "count_ascending_pairs.h"

size_t count_ascending_pairs(const int *input_array, size_t array_size)
{
    if (array_size < 2)
    {
        return 0;
    }

    size_t count = 0;
    for (size_t i = 1; i < array_size; i++)
    {
        if (input_array[i - 1] < input_array[i])
        {
            count++;
        }
    }
    return count;
}
