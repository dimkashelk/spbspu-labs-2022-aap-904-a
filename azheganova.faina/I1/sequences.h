#ifndef SEQUENCES_H
#define SEQUENCES_H

class Localminimals
{
  public:
    Localminimals(int previous);
    void operator()(int previous);
    unsigned int generalcount() const;
  private:
    unsigned int count = 0;
    int current = 0;
    int next = 0;
};

class Minsrmax
{
  public:
    Minsrmax(int previous);
    void operator()(int previous);
    unsigned int generalcount() const;
  private:
    unsigned int countofsequenceelements = 0;
    unsigned int count = 0;
    int current = 0;
    int next = 0;
};
#endif
