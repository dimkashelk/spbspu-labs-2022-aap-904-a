#ifndef ISFLOAT_HPP
#define ISFLOAT_HPP
bool isFloat(const char * n);
bool is_dot(char n);
bool continue_with_dot(const char * n);
bool is_digit(char n);
bool continue_with_digit(const char * n);
bool continue_with_E(const char * n);
bool is_E(char n);
bool continue_in_exponent(const char * n);
bool is_sign(char n);
bool next_digit(const char * n);
bool continue_with_sign(const char * n);
bool is_non_zero(char n);
bool is_end(char n);
#endif
