#ifndef WORKWITHSTRFUNCS_H
#define WORKWITHSTRFUNCS_H

#include <utility>
#include <algorithm>
#include <iostream>

char* reallocMem(char* str, const size_t& size, const size_t& new_capacity);
void pushBack(char* str, size_t& str_size, size_t& str_capasity);
std::pair<char*, char*> strCopy(const char* str);

#endif
