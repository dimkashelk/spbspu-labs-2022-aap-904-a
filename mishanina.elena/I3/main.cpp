#include <iostream>

int main()
{
  size_t capacity1 = 10;
  char* cstring1 = new char[capacity1];
  cstring1[0] = '\0';
  try
  {
    cstring1 = inputString(cstring1, capacity1, std::cin);
    if (cstring1[0] == '\0')
    {
      std::cout << "ERROR: empty string";
      delete[] cstring1;
      return 1;
    }
    cstring1[capacity1 - 1] = '\0';
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    delete[] cstring1;
    return 1;
  }
  char* destination = new char[capacity1];
  destination[0] = '\0';
  try
  {
    destination = removeExtraSpaces(destination, cstring1);
	std::cout << destination << "\n";
	delete[] destination;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
	delete[] destination;
	delete[] cstring1;
	return 1;
  }
  size_t capacity2 = 10;
  char* cstring2 = new char[capacity2];
  cstring2[0] = '\0';
  try
  {
    cstring2 = inputString(cstring2, capacity2, std::cin);
	if (capacity2 == 0)
	{
      cstring2[capacity2] = '\0';
	}
	else
	{
      cstring2[capacity2 - 1] = '\0';
	}
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
	delete[] cstring1;
	delete[] cstring2;
	delete[] destination;
	return 1;
  }
  try
  {
    bool result = hasItTheSameSimbols(cstring1, cstring2);
    if (result)
    {
      std::cout << "Strings have the same simbols" << "\n";
    }
    else
    {
      std::cout << "Strings don't have the same simbols" << "\n";
    }
    delete[] cstring1;
    delete[] cstring2;
  }
  catch (const std::exception& e)
  {
    std::cout << e.what();
    delete[] cstring1;
    delete[] cstring2;
    return 1;
  }
  return 0;
}
