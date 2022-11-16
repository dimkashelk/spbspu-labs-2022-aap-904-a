#ifndef SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
#define SPBSPU_LABS_2022_AAP_904_A_STRINGBUILDER_H
class StringBuilder
{
public:
  StringBuilder();
  void addChar(char);
private:
  char *str;
  size_t size;
  size_t capacity;
};
#endif
