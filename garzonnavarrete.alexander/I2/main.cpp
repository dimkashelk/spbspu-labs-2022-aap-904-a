#include <iostream>
#include <fstream>
#include <climits>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

void process_array(int* arr, size_t n)
{
    int max = INT_MIN;
    int min = INT_MAX;
    int imin = 0, imax = 0, suma = 0;
    double avg = 0.0;
    int c = 0;

    for (size_t i = 0; i < n; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            imin = i;
        }
        if (arr[i] > max)
        {
            max = arr[i];
            imax = i;
        }

        if (i % 2 == 0)
        {
            avg += arr[i];
            ++c;
        }
    }

    avg /= c;
    suma = imin + imax;

    cout << "The min element is: " << min << endl;
    cout << "The max element is: " << max << endl;
    cout << "The sum of indices of the max and min is: " << suma << endl;
    cout << "The average of elements at even indices is: " << avg << endl;
}

int main(int argc, char** argv)
{
    srand(time(NULL));
    int arr1[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 20};
    process_array(arr1, 18);
    size_t n;
    cin >> n;
    if (n > 0)
    {
        int* arr2 = new int[n];
        if (arr2 == NULL)
        {
            cerr << "Cannot allocate memory" << endl;
            return 1;
        }
        for(size_t i = 0; i < n; ++i) arr2[i] = rand();
        process_array(arr2, n);
        delete[] arr2;
    }
    if (argc > 1)
    {
        ifstream ifs;
        ifs.open(argv[1]);
        if (ifs)
        {
            ifs >> n;
            if (n > 0)
            {
                int* arr3 = new int[n];
                if (arr3 == NULL)
                {
                    cerr << "Cannot allocate memory" << endl;
                    return 2;
                }
                for(size_t i = 0; i < n; ++i) ifs >> arr3[i];
                process_array(arr3, n);
                delete[] arr3;
            }
            else
            {
                cerr << "Array is empty" << endl;
                return 3;
            }
        }
        else
        {
            cerr << "No input file" << endl;
            return 4;
        }
    }
}
