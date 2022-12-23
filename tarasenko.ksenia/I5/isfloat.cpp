#include "isfloat.hpp"

bool is_sign(char n)
{
  return (n == '+' || n == '-');
}
bool is_digit(char n)
{
  return (n >= '0' && n <= '9');
}
bool is_non_zero(char n)
{
  return (n > '0' && n <= '9');
}
bool is_end(char n)
{
  return (n == '\0');
}
bool is_dot(char n)
{
  return (n == '.');
}
bool is_E(char n)
{
  return (n == 'E');
}
bool next_digit(const char * n)
{
  return is_digit(*n) && (next_digit(n + 1) || is_end(*(n + 1)));
}
bool continue_in_exponent(const char * n)
{
  return (is_sign(*n) && continue_with_sign(n + 1)) || (is_non_zero(*n) && (next_digit(n + 1) || is_end(*(n + 1))));
}
bool continue_with_E(const char * n)
{
  return is_E(*n) && continue_in_exponent(n + 1);
}
bool continue_with_digit(const char * n)
{
  return is_digit(*n) && (continue_with_digit(n + 1) || continue_with_E(n + 1));
}
bool continue_with_dot(const char * n)
{
  return is_digit(*n) && (continue_with_digit(n + 1) || continue_with_E(n + 1));
}
bool continue_with_sign(const char * n)
{
  return is_non_zero(*n) && (next_digit(n + 1) || is_end(*(n + 1)));
}
bool isFloat(const char * n)
{
  return ((is_dot(*n) && continue_with_dot(n + 1)) || (is_sign(*n) && is_dot(*(n + 1)) && continue_with_dot(n + 2)));
}

