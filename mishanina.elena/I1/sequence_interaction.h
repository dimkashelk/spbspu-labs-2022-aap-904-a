#ifndef SEQUENCE_INTERACTION_H
#define SEQUENCE_INTERACTION_H

class Lab_I1
{
public:
  Lab_I1();
  void operator()(int n);
  int get_count() const;
  int get_count_after_max() const;
private:
  int n = 0;
  int old_n;
  int cur_n;
  int new_n;
  int count;
  int max_n;
  int count_after_max;
};

#endif
