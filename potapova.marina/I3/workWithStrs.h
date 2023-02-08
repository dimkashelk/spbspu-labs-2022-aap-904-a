#ifndef WORKWITHSTRS_H
#define WORKWITHSTRS_H

#include <utility>
#include <algorithm>
#include <iostream>

const size_t capasity_block = 100;

void pushBack(char*& str, size_t& str_size, size_t& str_capasity, const char& new_char);
std::pair<char*, char*> strCopy(const char* str);

#endif
