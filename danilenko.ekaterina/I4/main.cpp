#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cout << "Check parameters";
    return 1;
  }

  size_t rows = 0;
  size_t columns = 0;
  size_t matrix[1000];
  std::ifstream inp_file(argv[2]);
  inp_file >> rows >> columns;
  if (!inp_file.is_open())
  {
    std::cout << "Error. File not open" << '\n';
    return 1;
  }
  if (rows * columns > 1000)
  {
    std::cout << "Error. Too much data" << '\n';
    return 1;
  }
  if (rows == 0 && columns == 0)
  {
    std::cout << "Error. Matrix is empty" << '\n';
    return 1;
  }

  return 0;
}

/*size_t rows = 0;
  size_t columns = 0;
  std::ifstream in(argv[2]);
  in >> rows >> columns;
  if (!in)
  {
    std::cout << "Error1";
    return 1;
  }
  if (!strcmp(argv[1], "1"))
  {
    int matrix[1000];
    for (size_t i = 0; i < rows; i++)
    {
      for (size_t j = 0; j < columns; j++)
      {
        in >> matrix[rows * i + j];
        if (!in)
        {
          std::cout << "Error2";
          return 1;
        }
      }
    }
    std::ofstream out(argv[3]);
    size_t result = countColumnsWithAscElements(matrix, rows, columns);
    out << "Columns: " << result << "\n";
  }
  else if (!strcmp(argv[1], "2"))
  {
    int** matrix2 = new int* [rows];
    for (size_t i = 0; i < rows; i++)
    {
      matrix2[i] = new int [columns];
      for (size_t j = 0; j < columns; j++)
      {
        in >> matrix2[i][j];
        if (!in)
        {
          std::cout << "Error3";
          delete[] matrix2;
          return 1;
        }
      }
    }
    std::ofstream out(argv[3]);
    out << "Diagonals: " << countDiagonalsWithoutZero(matrix2, rows) << "\n";
    delete[] matrix2;
  }
  else
  {
    std::cout << "No such parameter";
    return 1;
  }*/