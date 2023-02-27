#include "reading_elements.h"
#include <stdexcept>
<<<<<<< HEAD
void readElements(int* matrix, size_t column, size_t line, std::istream& file_matrix_in)
=======
void readElements(int* matrix, size_t column, size_t line, std::ifstream& file_matrix_in)
>>>>>>> parent of 20dd5ff0 ( delete)
{
  for (size_t i = 0; i < column * line; i++)
  {
    file_matrix_in >> matrix[i];
    if (!file_matrix_in)
    {
      throw std::runtime_error("something went wrong..");
    }
  }
}
