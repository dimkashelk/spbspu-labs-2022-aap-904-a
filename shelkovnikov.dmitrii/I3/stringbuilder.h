#ifndef SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
#define SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
class StringBuilder
{
public:
  StringBuilder();
  ~StringBuilder();
  void add_char(char);
  size_t get_size();
  char* get_string();
  char get_char(int i);
  void remove_char(int ind);
private:
  void extend(int new_capacity);
  size_t size;
  size_t capacity;
  char *str;
};
#endif
