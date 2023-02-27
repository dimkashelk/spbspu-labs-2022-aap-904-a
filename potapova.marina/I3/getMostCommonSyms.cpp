#include <cstddef>
#include <cstdint>
#include <utility>
#include "getMostCommonSyms.h"

char* getMostCommonSyms(char* dest, const char* str)
{
    size_t counts[127];
    for (size_t& count : counts)
    {
        count = 0;
    }
    std::pair< char, size_t > ans_syms_cnts[3];
    for (; *str != '\0'; ++str)
    {
        std::pair< char, size_t > cur_elem_cnt(*str, ++counts[static_cast< size_t >(*str)]);
        for (auto& ans_sym_cnt : ans_syms_cnts)
        {
            if (cur_elem_cnt.first == ans_sym_cnt.first)
            {
                break;
            }
            if (cur_elem_cnt.second > ans_sym_cnt.second)
            {
                std::swap(ans_sym_cnt, cur_elem_cnt);
            }
        }
    }
    const std::pair< char, size_t >* ans_sym_cnt_ptr = ans_syms_cnts;
    for (char* dest_sym_ptr = dest;
        ans_sym_cnt_ptr < ans_syms_cnts + 3;
        ++ans_sym_cnt_ptr, ++dest_sym_ptr)
    {
        *dest_sym_ptr = ans_sym_cnt_ptr->first;
    }
    dest[3] = '\0';
    return dest;
}
