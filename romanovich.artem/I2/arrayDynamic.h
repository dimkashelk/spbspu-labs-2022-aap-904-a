#ifndef I2_ARRAYDYNAMIC_H
#define I2_ARRAYDYNAMIC_H
#include <stdexcept>
struct ArrayDynamic
{
  explicit ArrayDynamic(size_t size);
  ~ArrayDynamic();
  int *data;
  size_t size;
};
#endif
