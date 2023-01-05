#include <iostream>

char* makeNewStringWithoutRepeat(char* destination, const char* source1, const char* source2, size_t size)
{
  size_t new_elements = 0;
  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if (source1[i] == source2[j])
      {
        break;
      }
      else if (j == size - 1)
      {
        destination[new_elements++] = source1[i];
        break;
      }
    }
  }

  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = 0; j < size; j++)
    {
      if (source2[i] == source1[j])
      {
        break;
      }
      else if (j == size - 1)
      {
        destination[new_elements++] = source2[i];
        break;
      }
    }
  }
  destination[new_elements] = '\0';

  return destination;
}

int main() 
{
  const size_t size = 10;
  char source1[size] = "";
  char source2[size] = "";
  std::cout << "Enter first string: ";
  std::cin >> source1;
  std::cout << "Enter second string: ";
  std::cin >> source2;
  char* destination;
  destination = new char[27];
  
  destination = makeNewStringWithoutRepeat(destination, source1, source2, size);
 
  std::cout << "New string with uncommon elements: " << destination;
   
  return 0;
}