#ifndef I2_ARRAYDYNAMIC_H
#define I2_ARRAYDYNAMIC_H
struct ArrayDynamic
{
  explicit ArrayDynamic(size_t capacity);
  ~ArrayDynamic();
  int *data;
  size_t size;
};
#endif
