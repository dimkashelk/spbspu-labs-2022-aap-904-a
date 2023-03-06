#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "findAscendingColumns.h"
#include "getMinSumOfDiagonal.h"

int main(int argc, char* argv[]) {
    try {
        if (argc != 4) {
            throw std::invalid_argument("Error: Invalid arguments");
        }
        std::ifstream inFile(argv[2]);
        if (!inFile.is_open()) {
            throw std::runtime_error("Error: Input file could not be opened");
        }
        std::ofstream outFile(argv[3]);
        if (!outFile.is_open()) {
            throw std::runtime_error("Error: Output file could not be opened");
        }
        size_t rows = 0;
        size_t cols = 0;
        inFile >> rows >> cols;
        if (!inFile) {
            throw std::runtime_error("Error: File read error");
        }
        if (rows * cols > 1000) {
            throw std::invalid_argument("Error: Array too large");
        }
        if (std::strcmp(argv[1], "1") == 0) {
            int arr[1000];
            for (unsigned i = 0; i < rows * cols; i++) {
                inFile >> arr[i];
                if (!inFile) {
                    throw std::runtime_error("Error: File read error");
                }
            }
            outFile << countGrowingCols(static_cast<const int*>(static_cast<const void*>(arr)), rows, cols) << "\n";
        } else if (std::strcmp(argv[1], "2") == 0) {
            double arr[1000];
            for (unsigned i = 0; i < rows * cols; i++) {
                inFile >> arr[i];
                if (!inFile) {
                    throw std::runtime_error("Error: File read error");
                }
            }
            if (rows == 0 || cols == 0) {
                throw std::invalid_argument("Error: Empty array passed to function");
            }
            outFile << calcMinSummSecondaryDiagonal(arr, rows, cols) << "\n";
        } else if (std::strcmp(argv[1], "3") == 0) {
            char arr[1000];
            for (unsigned i = 0; i < rows * cols; i++) {
                inFile >> arr[i];
                if (!inFile) {
                    throw std::runtime_error("Error: File read error");
                }
            }
            // Call any function that you want to call for the third argument
        } else {
            throw std::invalid_argument("Error: Invalid argument");
        }
        if (!outFile) {
            throw std::runtime_error("Error: File write error");
        }
        return 0;
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << std::endl;
        return 1;
    }
}
