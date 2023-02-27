#include <cctype>
#include <cstring>
char* removeDuplicateSpaces(char* source)
{
  size_t size = 0;
  bool prev_space = false;
  for (size_t d = 0; source[d]; d++)
  {
    if (std::isspace(source[d]))
    {
      if (!prev_space)
      {
        source[size] = ' ';
        size++;
        prev_space = true;
      }
    }
    else
    {
      source[size] = source[d];
      size++;
      prev_space = false;
    }
  }
  if (size > 0 && std::isspace(source[size-1]))
  {
    size--;
  }
  source[size] = '\0';
  return source;
}
