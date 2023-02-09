int main(int argc, char * argv[])
{
  const size_t sizeOfDefaultArray = 10;
  int defaultArray[sizeOfDefaultArray] = { -5, 2, 1, 3, 2, 1, -2, 1, -3, -4 };
  size_t sizeOfDynArray = 0;
  std::cout << "Enter size of array: ";
  std::cin >> sizeOfDynArray;
  int* dynArray = new int[sizeOfDynArray];
  std::srand(time(nullptr));
  for (size_t i = 0; i < sizeOfDynArray; i++)
  {
    dynArray[i] = 1 + rand() % 9;
    dynArray[i] = 1 + rand() % 9 * -1;
  }
  delete[] dynArray;
}
