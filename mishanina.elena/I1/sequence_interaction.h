#ifndef SEQUENCE_INTERACTION_H
#define SEQUENCE_INTERACTION_H

class Lab_I1
{
public:
  Lab_I1(int n);
  void operator()();
  void conclusion();
private:
  int n = 0;
  static int old_n;
  static int cur_n;
  static int new_n;
  static int count;
  static int max_n;
  static int count_after_max;
};

#endif // !SEQUENCE_INTERACTION_H
