#ifndef WORKWITHSTRS_H
#define WORKWITHSTRS_H

#include <cassert>

#include <utility>
#include <algorithm>
#include <iostream>

const size_t CAPASITY_BLOCK = 100;

bool pushBack(char*& str, size_t& str_size, size_t& str_capasity, const char& new_char);
std::pair < char*, char* > strCopy(const char* str);

#endif
