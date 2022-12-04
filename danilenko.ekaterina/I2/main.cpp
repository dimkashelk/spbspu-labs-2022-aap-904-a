#include <iostream>
#include <fstream>
#include <stdexcept>
#include "MaxElements.h"
#include "PositiveRepeatingNumber.h"

int main(int argc, char *array[])
{
  if (argc != 2)
  {
    std::cerr << "Incorrect number of arguments";
    return 1;
  }
  
  size_t size1 = 10;
  int array1[10] = {1, 9, 8, 4, 9, 9, 9, 4 ,3, 2};
  try
  {
    std::cout << "Number of max elements: " << CountMaxElements(array1, size1) << "\n";
    std::cout << "Positive repeating numbers: " << PosRepeatingNum(array1, size1) << "\n\n";
  }
  catch (const std::overflow_error& e)
  {
    std::cout << "Error...";
    std::cout << e.what();
    return 0;
  }
  
  size_t size2 = 0;
  int* array2 = 0;
  std::cin >> size2;
  if (size2 >= 0)
  {
    array2 = new int[size2];
    std::srand(time(nullptr));
    for (size_t i = 0; i < size2; i++)
    {
      array2[i] = rand()%10;
    }
    try
    {
      std::cout << "Number of max elements: " << CountMaxElements(array2, size2) << "\n";
      std::cout << "Positive repeating numbers: " << PosRepeatingNum(array2, size2) << "\n\n";
    }
    catch (const std::overflow_error& e)
    {
      std::cout << "Error...";
      std::cout << e.what();
      delete[] array2;
      return 1;
    }
    delete[] array2;
  }
  else
  {
    std::cout << "Array is not possible" << "\n";
  }
  
  std::ifstream file;
  std::string name = array[1];
  file.open(name);
  if (file.is_open())
  {
    int* array3;
    size_t size3 = 0;
    file >> size3;
    if (file)
    {
      if (size3 > 0)
      {
        array3 = new int[size3];
        for (size_t i = 0; i < size3; i++)
        {
          file >> array3[i];
          if (!file)
          {
            std::cout << "File reading error" << "\n";
            delete[] array3;
            return 1;
          }
        }
        try
        {
          std::cout << "Number of max elements: " << CountMaxElements(array3, size3) << "\n";
          std::cout << "Positive repeating numbers: " << PosRepeatingNum(array3, size3) << "\n\n";
        }
        catch (const std::overflow_error& e)
        {
          std::cout << "Error...";
          std::cout << e.what();
          delete[] array3;
          return 1;
        }
        delete[] array3;
      }
    }
    else
    {
      std::cout << "File reading error" << "\n";
      return 1;
    }
  }
  else
  {
    std::cout << "File opening error" << "\n";
    return 1;
  }
  return 0;
}
