#include "defCountDiffLett.h"
#include <cstddef>

size_t defCountDiffLett(const char* cStr)
{
    bool letExist[26];
    size_t count = 0;

    for (size_t i = 0; i < 26; i++)
    {
        letExist[i] = 0;
    }
    for (size_t i = 0; cStr[i] != '\0'; i++)
    {
        if (int(cStr[i]) >= 97 && int(cStr[i]) <= 122)
        {
            letExist[int(cStr[i]) - 97] = 1;
        }
    }
    for (size_t i = 0; i < 26; i++)
    {
        count = count + letExist[i];
    }

    return count;
}
