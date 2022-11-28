#ifndef SEQUENCE_INTERACTION_H
#define SEQUENCE_INTERACTION_H

class Lab_I1
{
public:
  void operator()();
  void conclusion();
private:
  int n = 0;
  int old_n = 0;
  int cur_n = 0;
  int new_n = 0;
  int count = 0;
  int max_n = 0;
  int count_after_max = 0;
};

#endif // !SEQUENCE_INTERACTION_H