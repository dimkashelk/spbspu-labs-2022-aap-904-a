#include <iostream>
#include "EraseLatLet.h"
#include "StringPyQ.h"

char* makeNewCapacityCString(char* cstring, size_t& capacity, size_t size)
{
  char* newstring = new char[capacity + 20];
  for (auto i = cstring, j = newstring; i != cstring + size; ++i, ++j)
  {
    *j = *i;
  }
  capacity += 20;
  return newstring;
}

int main()
{
    // Read input string
    size_t capacity = 10;
    char* cstring = new char[capacity];
    cstring[0] = '\0';
    size_t size = 0;
    std::cin >> std::noskipws;
    do
    {
        if (size == capacity)
        {
            try
            {
                char* newCString = makeNewCapacityCString(cstring, capacity, size);
                delete[] cstring;
                cstring = newCString;
                newCString = nullptr;
            }
            catch (const std::exception& e)
            {
                std::cerr << e.what() << "\n";
                delete[] cstring;
                return 1;
            }
        }
        std::cin >> cstring[size];
    } while (std::cin && cstring[size++] != '\n');

    if (cstring[0] == '\0' || cstring[0] == '\n')
    {
        std::cout << "Error while reading the string \n";
        delete[] cstring;
        return 2;
    }

    cstring[size - 1] = '\0';

    // Test sum_strings function
    char* sum_result = nullptr;
    try
    {
        sum_result = new char[size * 2];
        sum_strings(sum_result, cstring, cstring);
        std::cout << "Sum of two strings: " << sum_result << "\n";
        delete[] sum_result;
        sum_result = nullptr;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        delete[] sum_result;
        delete[] cstring;
        return 3;
    }

    // Test eraseLatLet function
    char* erase_result = nullptr;
    try
    {
        erase_result = new char[size];
        erase_result = eraseLatLet(erase_result, cstring);
        if (erase_result[0] != '\0')
        {
            std::cout << "Text without latin letters: " << erase_result << "\n";
        }
        else
        {
            std::cout << "Error while removing latin letters \n";
        }
        delete[] erase_result;
        erase_result = nullptr;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << "\n";
        delete[] erase_result;
        delete[] cstring;
        return 4;
    }

    delete[] cstring;
    return 0;
}
