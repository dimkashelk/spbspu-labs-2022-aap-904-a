#ifndef SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
#define SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
#include <cstddef>
class StringBuilder
{
public:
  StringBuilder();
  ~StringBuilder();
  void add_char(char new_char);
  size_t get_size();
  char* get_string();
  char get_char(size_t i);
  void remove_char(size_t ind);
private:
  void extend(int new_capacity);
  size_t size;
  size_t capacity;
  char *str;
};
#endif
