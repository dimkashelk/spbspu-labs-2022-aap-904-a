#ifndef WORKWITHSTRFUNCS_H
#define WORKWITHSTRFUNCS_H

#include <iostream>
#include <algorithm>
#include <utility>

char* reallocMem(char* str, const size_t& size, const size_t new_capacity);
void pushBack(char* str, size_t& str_size, size_t& str_capasity);


#endif
