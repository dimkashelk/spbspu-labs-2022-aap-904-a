#include "check_input_data.h"

bool checkInputData(size_t nRows, size_t nColomns)
{
  return (((nRows == 0) || (nColomns == 0)) || (nRows != nColomns));
}
