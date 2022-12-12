#include<iostream>

int main()
{
  size_t capacity = 10;
  char * cstring = new char[capacity];
  size_t size = 0;

  std::cin >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      try
      {
        char * newstr = new char[capacity + 20];
        for (auto i = cstring, j = newstr; i != cstring + size; ++i, ++j)
        { 
          *j = *i;
        }
        delete [] cstring;
        cstring = newstr;
        capacity += 20;
      }
      catch (...)
      {
        delete [] cstring;
        return 1;
      }
    }
    std::cin >> cstring[size];
  }
  while (std::cin && cstring[size++] != '\n');
  cstring[size - 1] = '\0';
  size--;

  size_t n = 0;
  size_t k = 0;
  char * cstring_2 = new char[size];

  while (std::isspace(cstring[n]))
  {
    n++;
  }

  for (size_t i = n; i < size; i++)
  {
    if (!(std::isspace(cstring[i]) && cstring[i] == cstring[i - 1]))
    {
      cstring_2[k] = cstring[i];
      k++;
    }
  }

  if (std::isspace(cstring_2[k - 1]))
  {
    k--;
  }

  cstring_2[k] = '\0';
  std::cout << cstring_2 << '\n';

  delete [] cstring;
  delete [] cstring_2;
}
