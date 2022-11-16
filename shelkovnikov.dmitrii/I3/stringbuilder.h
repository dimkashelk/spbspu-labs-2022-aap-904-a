#ifndef SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
#define SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
class StringBuilder
{
public:
  StringBuilder();
  void addChar(char);
private:
  void extend(int new_capacity);
  size_t size;
  size_t capacity;
  char *str;
};
#endif
