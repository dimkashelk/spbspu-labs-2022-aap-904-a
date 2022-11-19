#ifndef MAXSEQLEN_HPP
#define MAXSEQLEN_HPP

struct MaxSeqLen
{
  void operator()(int value);

  unsigned int upseqcounter;
  unsigned int maxupseqcount;
  int prevalue;
};
#endif

