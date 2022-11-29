#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <cstddef>
#include <fstream>
namespace turkin
{
  struct Array
  {
  explicit Array(size_t cap);
  ~Array();

  char buffer = '\0';
  char * data;
  size_t size;
  size_t capacity;

  bool extend();
  bool push(std::istream & cin);
  bool push(char symbol);
  };
}
#endif
