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

  bool push(char symbol);
  char * data;
  size_t size;
  size_t capacity;

  private:
    const size_t extendSize = 10;
    char * extendBuffer = nullptr;
    bool extend();
  };
}
#endif
