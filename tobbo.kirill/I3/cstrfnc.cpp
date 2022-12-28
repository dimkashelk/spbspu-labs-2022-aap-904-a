#include "cstrfnc.h"
#include <cmath>
#include <stdexcept>

char* getCString(std::istream& stream)
{
  size_t size = 0;
  size_t capacity = 10;
  char* str = new char[capacity];
  str[0] = '\0';
  stream >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      capacity = static_cast< size_t >(capacity * std::sqrt(2));
      char* newstr = new char[capacity];
      for (auto i = str, j = newstr; i != str + size; ++i, ++j)
      {
        *j = *i;
      }
      delete[] str;
      str = newstr;
    }
    stream >> str[size++];
  }
  while (std::cin && str[size - 1] != '\n');

  //if (str[0] == '\0' || str[0] == '\n')
//  {
  //  delete[] str;
//    throw std::invalid_argument("Empty string is not allowed");
//  }
  str[size - 1] = '\0';

  std::cout << "Received: '" << str << "'\n";

  return str;
}

size_t strLength(const char* str)
{
  size_t size = 0;
  size_t i = 0;
  while (str[i++] != '\0')
  {
    size++;
  }
  return size;
}

bool isIntersectedStrings(char* str1, char* str2)
{
  size_t index1 = 0;
  while (str1[index1] != '\0')
  {
    size_t index2 = 0;
    while (str2[index2] != '\0')
    {
      if (str1[index1] == str2[index2])
      {
        return true;
      }
      index2++;
    }
    index1++;
  }
  return false;
}

char* removeLatinVowelSymbols(char* destination, const char* source)
{
  const char vowels[] = "AaEeIiOoUu";
  size_t vowels_size = sizeof(vowels);
  size_t size = strLength(source);
  size_t dest_index = 0;
  for (size_t i = 0; i < size; i++)
  {
    bool found = false;
    for (size_t j = 0; j < vowels_size; j++)
    {
      if (source[i] == vowels[j])
      {
        found = true;
        break;
      }
    }
    if (!found)
    {
      destination[dest_index++] = source[i];
    }
  }
  destination[dest_index] = '\0';
  return destination;
}
