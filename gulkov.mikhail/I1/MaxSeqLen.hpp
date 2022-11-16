#ifndef MAXSEQLEN_HPP
#define MAXSEQLEN_HPP

struct MaxSeqLen
{
  void operator()(int value);
  unsigned int upseqcounter = 0;
  unsigned int maxupseqcount = 0;
  int prevalue = 0;
};
#endif
