#include "max_seq_cnt.h"
#include <limits>
#include <stdexcept>

void MaxSeqRow::operator()(int value)
{
  func_value = value;
  func_previous_value = func_value;
  if (func_value && func_previous_value)
  {
    if (current_seq_row > max_seq_row)
    {
      max_seq_row = current_seq_row;
    }
    else
    {
      current_seq_row = 0;
    }
  }
}
