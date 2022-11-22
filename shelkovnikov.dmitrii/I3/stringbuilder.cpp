#include "stringbuilder.h"
#include <limits>
#include <stdexcept>
StringBuilder::StringBuilder():
  size(0),
  capacity(10),
  str(new char[capacity])
{}
void StringBuilder::add_char(char new_char)
{
  constexpr size_t max_size_t = std::numeric_limits< size_t >::max();
  if (size == capacity)
  {
    if (capacity == max_size_t)
    {
      throw std::overflow_error("Too much numbers");
    }
    if (max_size_t - 10 <= capacity)
    {
      capacity = max_size_t;
    }
    capacity += 10;
    extend(capacity);
  }
  str[size] = new_char;
  size++;
}
size_t StringBuilder::get_size()
{
  return size;
}
char* StringBuilder::get_string()
{
  char *dop = new char[size];
  for (size_t i = 0; i < size; i++)
  {
    dop[i] = str[i];
  }
  return dop;
}
char StringBuilder::get_char(size_t i)
{
  if (i >= size)
  {
    throw std::runtime_error("Going beyond the line");
  }
  return str[i];
}
void StringBuilder::remove_char(size_t ind)
{
  if (ind >= size)
  {
    throw std::runtime_error("Going beyond the line");
  }
  for (size_t i = ind; i < size - 1; i++)
  {
    str[i] = str[i + 1];
  }
  size--;
}
void StringBuilder::extend(int new_capacity)
{
  char *new_str = new char[new_capacity];
  for (size_t i = 0; i < size; i++)
  {
    new_str[i] = str[i];
  }
  delete[] str;
  str = new_str;
}
StringBuilder::~StringBuilder()
{
  delete[] str;
}
