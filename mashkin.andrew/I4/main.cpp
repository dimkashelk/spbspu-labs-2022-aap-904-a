#include <iostream>

int main(int argc, char** argv)
{
  if (argc != 4)
  {
    std::cout << "Error with arguments";
    return 1;
  }
  if (!std::strcmp(argv[1], "1"))
  {
    std::ifstream inpFile;
    inpFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
      inpFile.open(argv[2]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    int stMatrix[1000];
    size_t rows = 0, cols = 0;
    inpFile >> rows;
    inpFile >> cols;
    inpFile.close();
    std::ofstream outFile;
    outFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
      outFile.open(argv[3]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    return 0;
  }
  else if (!std::strcmp(argv[1], "2"))
  {
    std::ifstream inpFile;
    inpFile.exceptions(std::ifstream::badbit | std::ifstream::failbit);
    try
    {
      inpFile.open(argv[2]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    inpFile.close();
    std::ofstream outFile;
    outFile.exceptions(std::ofstream::badbit | std::ofstream::failbit);
    try
    {
      outFile.open(argv[3]);
    }
    catch (const std::exception& ex)
    {
      std::cout << ex.what() << "\n";
      return 1;
    }
    return 0;
  }
  else
  {
    std::cout << "Incorect arg " << argv[1] << "\n";
    return 1;
  }
}