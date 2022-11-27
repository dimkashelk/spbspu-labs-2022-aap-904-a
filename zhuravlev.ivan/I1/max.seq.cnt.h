#ifndef MAX_SEQ_CNT_H
#define MAX_SEQ_CNT_H

struct MaxSeqRow
{
  void operator()(int value, int previous_value);

  int func_value;
  int func_previous_value;
  unsigned int current_seq_row;
  unsigned int max_seq_row;
};
#endif
