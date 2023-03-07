#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "findAscendingColumns.h"
#include "getMinSumOfDiagonal.h"

void readArrayFromFile(std::ifstream& inFile, int* arr, size_t rows, size_t cols)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < cols; j++)
        {
            if (!(inFile >> arr[i * cols + j]))
            {
                throw std::runtime_error("Error: File read error");
            }
        }
    }

    if (inFile >> std::ws && !inFile.eof())
    {
        throw std::runtime_error("Error: Too much data in input file");
    }
}
int main(int argc, char * argv[])
{
    try
    {
        if (argc != 4)
        {
            throw std::invalid_argument("Error: Invalid number of arguments");
        }

        std::ifstream inFile(argv[2]);
        if (!inFile.is_open())
        {
            throw std::runtime_error("Error: Input file could not be opened");
        }

        std::ofstream outFile(argv[3]);
        if (!outFile.is_open())
        {
            throw std::runtime_error("Error: Output file could not be opened");
        }

        size_t rows = 0;
        size_t cols = 0;
        inFile >> rows >> cols;
        if (!inFile)
        {
            throw std::runtime_error("Error: File read error");
        }

        if (rows * cols > 1000)
        {
            throw std::invalid_argument("Error: Array too large");
        }

        int *arr = new int[rows * cols];

        if (std::strcmp(argv[1], "1") == 0)
        {
            readArrayFromFile(inFile, arr, rows, cols);
            if(cols > 0 && rows > 0){
                outFile << countGrowingCols(arr, rows, cols) << "\n";
            }
            delete[] arr;
            inFile.close();
            outFile.close();
            return 0;
        }
        else if (std::strcmp(argv[1], "2") == 0)
        {
            readArrayFromFile(inFile, arr, rows, cols);
            if(cols > 0 && rows > 0){
                outFile << calcMinSummSecondaryDiagonal(arr, rows, cols) << "\n";
            }
            delete[] arr;
            inFile.close();
            outFile.close();
            return 0;
        }
        else if (std::strcmp(argv[1], "3") == 0)
        {
            readArrayFromFile(inFile, arr, rows, cols);
            // process array
            delete[] arr;
            inFile.close();
            outFile.close();
            return 0;
        }
        else
        {
            throw std::invalid_argument("Error: Invalid argument");
        }
        inFile.close();
        outFile.close();

    }
    catch (const std::exception & ex)
    {
        std::cerr << ex.what() << std::endl;
        return 1;
    }

    return 0;
}
