#include "i3-3.h"
#include "i3-12.h"

char* read_str(istream& ifs, char* dst)
{
  int n = 0;
  while (!ifs.eof())
  {
    ifs.get(dst[n]);
    if (dst[n] == '\n') break;
    ++n;
  }
  dst[n] = 0;
  return dst;
}
char* remove_roman(char* dst, char* src)
{
  int i = 0, j = 0;
  do
  {
    if ((src[i] < 'A') || (src[i] > 'z') || ((src[i] > 'Z') && (src[i] < 'a')))
    {
      dst[j] = src[i];
      ++j;
    }
    ++i;
  } while (src[i] != 0);
  dst[j] = 0;
  return dst;
}
char* merge(char* dst, char* s1, char* s2)
{
  int j = 0;
  int i1 = 0;
  int i2 = 0;
  do
  {
    if (i1 >= 0)
    {
      if (s1[i1] != 0)
      {
        dst[j] = s1[i1];
        ++j;
        ++i1;
      }
      else
      {
        i1 = -1;
      }
    }
    if (i2 >= 0)
    {
      if (s2[i2] != 0)
      {
        dst[j] = s2[i2];
        ++j;
        ++i2;
      }
      else
      {
        i2 = -1;
      }
    }
  } while ((i1 >= 0) || (i2 >= 0));
    dst[j] = 0;
    return dst;
}
int main() {
    //setlocale(LC_ALL, "ru_RU");
    int maxn;
    ifstream ifs;
    ofstream ofs;
    char* s = NULL; // ADDED: = NULL (to enable checking if we should release anything in the end)
    char* s2 = NULL;
    char* c = NULL;

    try {
        ifs.open("input_str3.txt");
    }
    catch (exception e) {
        cerr << "Mission 3 failed: could not open file. Trying mission 12." << endl; // CHANGED: cout ---> cerr (stderr, not stdout, they want it!)
        goto maybe_12;
    }
    if (!ifs) { // ADDED THIS: just no input file (and no other issues) does not throw an exception, it is just NULL in ifs
        cerr << "Mission 3 failed: could not open file. Trying mission 12." << endl;
        goto maybe_12;
    }
    ifs >> maxn;
    try {
        s = new char[maxn];
    }
    catch (exception e) {
        ifs.close();
        cerr << e.what() << endl; // CHANGED: cout ---> cerr
        return -1;
    }
    try {
        c = new char[maxn];
    }
    catch (exception e) {
        ifs.close();
        delete s;
        cerr << e.what() << endl; // CHANGED: cout ---> cerr
        return -1;
    }
    ifs.ignore(256, '\n');
    read_str(ifs, s);
    ifs.close();
    remove_roman(c, s);
    cout << c << endl;
    try {
        ofs.open("output_str.txt");
        ofs << c;
        ofs.close();
    }
    catch (exception e)
    {
        cerr << e.what() << endl; // CHANGED: cout ---> cerr
    }
    if (c != NULL) delete c;// ADDED: != NULL
    if (s != NULL) delete s;
    cout << endl;

maybe_12:
    try {
        ifs.open("input_str12.txt");
    }
    catch (exception e) {
        cerr << "Mission 12 failed: could not open file." << endl; // CHANGED: cout ---> cerr
        return -1;
    }
    if (!ifs) { // ADDED THIS: just no input file (and no other issues) does not throw an exception, it is just NULL in ifs
        cerr << "Mission 12 failed: could not open file." << endl;
        return -1;
    }

    ifs >> maxn;
    try {
        s = new char[maxn];
    }
    catch (exception e) {
        cerr << e.what() << endl; // CHANGED: cout ---> cerr
        ifs.close();
        return -1;
    }
    try {
        s2 = new char[maxn];
    }
    catch (exception e) {
        cerr << e.what() << endl; // CHANGED: cout ---> cerr
        delete s;
        ifs.close();
        return -1;
    }
    ifs.ignore(256, '\n');
    read_str(ifs, s);
    read_str(ifs, s2);
    ifs.close();

    try {
        c = new char[maxn * 2];
    }
    catch (exception e) {
        cerr << e.what() << endl;  // CHANGED: cout ---> cerr
        delete s;
        delete s2;
        return -1;
    }
    cout << s << endl << "+" << endl;
    cout << s2 << endl << "=" << endl;

    merge(c, s, s2);
    cout << c << endl;

    try {
        ofs.open("output_str12.txt");
        ofs << c;
        ofs.close();
    }
    catch (exception e)
    {
        cout << e.what() << endl;
    }
    if (c != NULL) delete c; // ADDED: check for NULL
    if (s != NULL) delete s;
    if (s2 != NULL) delete s2;
    return 0;
}
