#ifndef GETUNIQUESYMBOLS_HPP
#define GETUNIQUESYMBOLS_HPP

#include <cstddef>

char *
get_unique_symbols(char *arr_unique, unsigned int size_unique, unsigned int capacity_unique, const char *cstring_one,
                   unsigned int size_one, const char *cstring_two, unsigned int size_two);

#endif
