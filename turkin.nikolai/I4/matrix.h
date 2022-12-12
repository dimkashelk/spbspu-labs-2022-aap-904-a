#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
#include <fstream>
namespace turkin
{
  struct Matrix
  {
    explicit Matrix(size_t mx, size_t my);
    ~Matrix();

    int * data;
    size_t mx;
    size_t my;
    size_t size;
  };

  void set(Matrix & matrix, std::ifstream & input);
  void set(Matrix & matrix, size_t mx, size_t my, int data);
  int get(const turkin::Matrix & matrix, size_t mx, size_t my);
  int * getRow(const turkin::Matrix & matrix, size_t row);
  int * getColumn(const turkin::Matrix & matrix, size_t column);
}
#endif
