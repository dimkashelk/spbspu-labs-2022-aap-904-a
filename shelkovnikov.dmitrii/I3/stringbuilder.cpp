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
  char *dop = new char[size + 1];
  for (size_t i = 0; i < size; i++)
  {
    dop[i] = str[i];
  }
  dop[size] = '\0';
  return dop;
}
char StringBuilder::get_char(size_t i)
{
  return str[i];
}
void StringBuilder::remove_char(size_t ind)
{
  for (int i = ind; i < size - 1; i++)
  {
    str[i] = str[i + 1];
  }
  size--;
}
void StringBuilder::extend(int new_capacity)
{
  char *new_str = new char[new_capacity];
  for (int i = 0; i < size; i++)
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
