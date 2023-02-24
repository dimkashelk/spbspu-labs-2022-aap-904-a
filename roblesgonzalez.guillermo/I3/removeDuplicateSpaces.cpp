#include <cctype>
#include <cstring>

char* removeDuplicateSpaces2(const char* source)
{
  char* destination = new char[strlen(source) + 1];
  size_t size = 0;
  size_t d = 0;
  while (std::isspace(source[d]))
  {
    d++;
  }
  while (source[d])
  {
    if (std::isspace(source[d]))
    {
      char space_char = source[d];
      while (std::isspace(source[d]))
      {
        d++;
      }
      destination[size] = space_char;
      size++;
    }
    else
    {
      destination[size] = source[d];
      size++;
    }
    d++;
  }
  if (size > 0)
  {
    size--;
    while (std::isspace(destination[size]))
    {
      size--;
    }
    size++;
  }
  destination[size] = '\0';
  return destination;
}
