#include "stringbuilder.h"
StringBuilder::StringBuilder():
  size(0),
  capacity(8),
  str(new char[capacity])
{}
void StringBuilder::add_char(char new_char)
{
  if (size == capacity)
  {
    capacity *= 2;
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
  return str;
}
void StringBuilder::extend(int new_capacity)
{
  char *new_str = new char[new_capacity];
  for (int i = 0; i < size; i++)
  {
    new_str[i] = str[i];
  }
  str = new_str;
  delete[] new_str;
}
