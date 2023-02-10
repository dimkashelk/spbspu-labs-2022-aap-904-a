#ifndef MAXSEQLEN_HPP
#define MAXSEQLEN_HPP

struct MaxSeqLen
{
  unsigned int upseqcounter;
  unsigned int maxupseqcount;
  int prevalue;

  void operator()(int value);
};
#endif
