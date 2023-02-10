#include <iostream>
int main()
{
  int value = 0;
  int predvalue = 0;
  int count = 0;
  int seqcount = 1;
  int maxseq = 0;
  std::cin >> value;
  while (value != 0) {
    predvalue = value;
    std::cin >> value;
    if (value == 0) {
      if (seqcount > maxseq) {
        maxseq = seqcount;
      }
      break;
    }
    if (predvalue < value) {
      count++;
    }
    if (predvalue > value) {
      seqcount++;
    } else {
      if (seqcount > maxseq) {
        maxseq = seqcount;
      }
      seqcount = 1;
    }
  }
  std::cout << maxseq << " " << count << "\n";
}
