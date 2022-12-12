#include <iostream>
#include <limits>


char* get_cstring(std::istream& stream)
{
  size_t capacity = 10;
  char* str = new char[capacity];
  size_t size = 0;
  stream >> std::noskipws;
  do
  {
    if (size == capacity)
    {
      capacity = (size_t)(capacity * std::sqrt(2));
      char* newstr = new char[capacity];
      for (auto i = str, j = newstr; i != str + size; ++i, ++j)
      {
        *j = *i;
      }
      delete[] str;
      str = newstr;
    }
    stream >> str[size];
  } while (std::cin && str[size++] != '\n');
  if (!std::cin && !size)
  {
    delete[] str;
    throw "Error while input";
  }
  str[size - 1] = '\0';

  return str;
}

bool is_intersected_strings(char* str1, char* str2)
{
  size_t index1 = 0;
  while (str1[index1] != '\0')
  {
    size_t index2 = 0;
    while (str2[index2] != '\0')
    {
      if (str1[index1] == str2[index2])
        return true;
      index2++;
    }
    index1++;
  }
  return false;
}

size_t str_length(const char* str)
{
  size_t size = 0;
  int i = 0;
  while (str[i++] != '\0')
    size++;
  return size;
}
char* remove_latin_vowel_letters_(char* destination, const char* source)
{
  const char vowels[] = "AaEeIiOoUu";
  size_t vowels_size = sizeof(vowels);
  size_t size = str_length(source);
  size_t dest_index = 0;
  for (int i = 0; i < size; i++)
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
      destination[dest_index++] = source[i];
  }
  destination[dest_index] = '\0';
  return destination;
}

void remove_latin_vowel_letters(const char* str)
{
  size_t size = str_length(str);
  char* destination = new char[size + 1];
  char* res2 = remove_latin_vowel_letters_(destination, str);
  std::cout << str << " => " << res2 << std::endl;
  delete[] destination;
}

int main()
{
  int rc = 0;
  char* str1 = NULL, * str2 = NULL;
  try
  {
    str1 = get_cstring(std::cin);
    str2 = get_cstring(std::cin);

    bool res1 = is_intersected_strings(str1, str2);
    std::cout << "There is " << (res1 ? "" : "NO") << " intersect symbols" << std::endl;

    remove_latin_vowel_letters(str1);
    remove_latin_vowel_letters(str2);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    rc = 1;
  }
  delete[] str1;
  delete[] str2;
  return rc;
}
