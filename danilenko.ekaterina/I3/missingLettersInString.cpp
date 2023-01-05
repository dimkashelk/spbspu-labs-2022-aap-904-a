#include <iostream>
#include <cctype>

char* missingLettersInString(char* destination, const char* source)
{
  size_t new_elements = 0;
  bool match = false;
  for (char i = 'a'; i <= 'z'; i++)
  {
    match = false;
    for (size_t j = 0; source[j] != '\0'; j++)
    {
      if (std::tolower(source[j]) == std::tolower(i))
      {
        match = true;
      }
    }
    if (match == false)
    {
      destination[new_elements++] = i;
    }
  }

  destination[new_elements] = '\0';

  return destination;
}

int main()
{
  char source[10] = "";
  std::cout << "Enter a string: ";
  std::cin >> source;
  char* destination;
  destination = new char[27];

  destination = missingLettersInString(destination, source);
  std::cout << destination << '\n';

  return 0;
}