#include "check_input_data.h"

bool checkInputData(size_t nRows, size_t nColomns)
{
  if ((nRows <= 0) || (nColomns <= 0))
  {
    return false;
  }
  else if (nRows != nColomns)
  {
    return false;
  }
  else
  {
    return true;
  }
}
