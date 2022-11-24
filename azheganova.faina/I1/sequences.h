#ifndef SEQUENCES_H
#define SEQUENCES_H

class Localminimals
{
  public:
    Localminimals(int min);
    void operator()(int previous);
    unsigned int generalcount() const;
  private:
    unsigned int count;
    int current;
    int next;
};

class Minsrmax
{
  public:
    Minsrmax(int sr);
    void operator()(int previous);
    unsigned int generalcount() const;
  private:
    unsigned int countofsequenceelements;
    unsigned int count;
    int current;
    int next;
};
#endif
