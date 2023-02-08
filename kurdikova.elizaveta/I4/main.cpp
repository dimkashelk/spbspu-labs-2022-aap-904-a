#include <iostream>
#include <cstring>
#include "PositiveRows.h"
#include "ReadMatrix.h"
#include "MinDiagonalSum.h"

int main(int argc, char* argv[])
  {
    // Проверка входных аргументов командной строки
    if (argc != 4)
    {
      std::cerr << "Ошибка! Неверное кол-во аргументов";
      return 1;
    }
    const char* taskNumber = argv[1];
    if (std::strcmp(taskNumber, "1") && std::strcmp(taskNumber, "2"))
    {
      std::cerr << "Ошибка! Неверный номер задания. Номер задания должен быть равен 1 или 2";
      return 2;
    }

    std::ifstream inputFile(argv[2]);
    std::ofstream outputFile(argv[3]);
    if (!inputFile.is_open())
    {
      std::cerr << "Ошибка! Не удаётся открыть входной файл";
      return 3;
    }
    else if (!outputFile.is_open())
    {
      std::cerr << "Ошибка! Не удаётся открыть выходной файл";
      return 4;
    }

    size_t rows = 0;
    size_t columns = 0;
    inputFile >> rows >> columns;
    if (!inputFile)
    {
      std::cerr << "Ошибка! Возникла ошибка при считывании размера матрицы";
      return 5;
    }
    if (rows * columns > 1000)
    {
      std::cerr << "Ошибка! Размер матрицы превышает 1000 элементов";
      return 6;
    }

    // Запуск заданий
    if (!std::strcmp(taskNumber, "1"))
    {
      int matrix[1000];
      try
      {
        readMatrixFromFile(matrix, rows, columns, inputFile);
      }
      catch (const std::runtime_error& e)
      {
        std::cerr << e.what() << "\n";
        return 7;
      }
      size_t result = getPosRowsCount(matrix, rows, columns);
      outputFile << result << "\n";
      std::cout << result;
      if (!outputFile)
      {
        std::cerr << "Ошибка! Возникла ошибка при записи результата в выходной файл";
        return 8;
      }
    }
    else
    {
      if (rows != columns || rows == 0)
      {
        std::cerr << "Ошибка! Заданные размеры матрицы не соответствуют квадратной матрице";
        return 9;
      }
      int* matrix = nullptr;
      try
      {
        matrix = new int[rows * columns];
        matrix = readMatrixFromFile(matrix, rows, columns, inputFile);
      }
      catch (const std::exception& e)
      {
        std::cerr << e.what() << "\n";
        delete[] matrix;
        return 7;
      }
      size_t result = minDiagonalSumParallelToSecondary(matrix, rows);
      outputFile << minDiagonalSumParallelToSecondary(matrix, rows) << "\n";
      std::cout << result;
      if (!outputFile)
      {
        std::cerr << "Ошибка! Возникла ошибка при записи результата в выходной файл";
        delete[] matrix;
        return 8;
      }
      delete[] matrix;
    }
    inputFile.close();
    outputFile.close();
    return 0;
  }

