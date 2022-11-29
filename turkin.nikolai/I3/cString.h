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

  char * data;
  size_t size;
  size_t capacity;

  bool extend(size_t cap);
  bool push(std::istream & cin);
  bool push(char symbol);
  };
}
#endif
