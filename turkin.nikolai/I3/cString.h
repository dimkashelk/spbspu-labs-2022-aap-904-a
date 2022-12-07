#ifndef CSTRING_H
#define CSTRING_H
#include <cstddef>
namespace turkin
{
  struct String
  {
    explicit String(size_t cap);
    ~String();

    char * data;
    size_t size;
    size_t capacity;

    void push(char symbol);

    private:
      const size_t extendSize = 10;
      char * extendBuffer = nullptr;
      void extend();
  };
}
#endif
