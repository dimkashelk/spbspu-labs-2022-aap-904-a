#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <format>

std::string count_of_maxes(const int* arr, size_t size);
std::string shift_part_to_end(int* arr, size_t size, unsigned int m, unsigned int n);

void processStaticArray();
void processDynamicArray();
void processFileArray(char* filename);


int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Wrong number of parameters. Should be one" << std::endl;
    return (int)1;
  }
  try
  {
    processStaticArray();
    processDynamicArray();
    processFileArray(argv[1]);
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}

void processStaticArray() {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  std::cout << count_of_maxes(arr, 10) << std::endl;
  std::cout << shift_part_to_end(arr, 10, 0, 5) << std::endl;
}

void processDynamicArray() {
  int n = 0;

  std::cout << "Enter array size:";
  std::cin >> n;

  if (std::cin.fail() || std::cin.peek() != 10 || n < 1)
    throw "Array size must be integer greater than 0.";

  srand((unsigned)time(NULL));

  int* arr = new int[n];
  int count = 0;

  std::cout << "Array:";
  for (int i = 0; i < n; ++i)
  {
    arr[i] = rand() % 200 - 100;
    std::cout << " " << arr[i];
  }
  std::cout << std::endl;

  std::cout << count_of_maxes(arr, n) << std::endl;
  std::cout << shift_part_to_end(arr, n, 0, 5) << std::endl;
}

void processFileArray(char* filename) {
  /*Process array  taken from file*/

  std::ifstream input(filename);
  if (!input.is_open()) {
    throw "Error while opening file";
  }
  while (!input.eof()) {
    size_t size = 0;
    input >> size;
    if (!input) {
      throw "Error while reading file";
    }

    int* arr_file = new int[size];
    for (size_t i = 0; i < size; i++) {
      input >> arr_file[i];
      if (!input) {
        delete[] arr_file;
        throw "Error while reading file";
      }
    }

    std::cout << count_of_maxes(arr_file, size) << std::endl;
    std::cout << shift_part_to_end(arr_file, size, 0, size / 2) << std::endl;

    delete[] arr_file;
  }
}

std::string count_of_maxes(const int* arr, size_t size) {
  int maximum = 0;
  int countMaximum = INT_MIN;
  for (int i = 0; i < size; i++) {
    if (arr[i] > maximum) {
      maximum = arr[i];
      countMaximum = 1;
    }
    else {
      if (arr[i] == maximum) {
        countMaximum++;
      }
    }
  }
  std::cout << maximum << std::endl;
  std::cout << countMaximum << std::endl;
  return "---------------";
}

std::string shift_part_to_end(int* arr, size_t size, unsigned int m, unsigned int n) {
  int part_size = n - m;

  for (int i = 0; i < part_size; i++) {
    int tmp = arr[size - i - 1];
    arr[size - i - 1] = arr[n - i -1];
    arr[n - i -1] = tmp;
  }

  std::ostringstream os;
  for (int j = 0; j < size; j++) {
    os << arr[j] << " ";
  }
  std::string str(os.str());

  return str;
}
