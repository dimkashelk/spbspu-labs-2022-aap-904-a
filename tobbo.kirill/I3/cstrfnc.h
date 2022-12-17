#ifndef CSTRFNC_H
#define CSTRFNC_H

#include <cstddef>
#include <iostream>


char* get_cstring(std::istream& stream);
size_t str_length(const char* str);

bool is_intersected_strings(char* str1, char* str2);
char* remove_latin_vowel_letters(char* destination, const char* source);

#endif
