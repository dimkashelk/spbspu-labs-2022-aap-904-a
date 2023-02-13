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

int main(int argc, char** argv) {
    srand(time(NULL));
    size_t n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n > 0) {
        int *arr = new int[n];
        if (arr == NULL) {
            cerr << "Cannot allocate memory" << endl;
            return 1;
        }
        cout << "Enter the elements of the array: " << endl;
        for (size_t i = 0; i < n; ++i)
            cin >> arr[i];
        process_array(arr, n);
        delete[] arr;
    } else {
        cerr << "Array size must be positive." << endl;
        return 3;
    }

    if (argc > 1) {
        ifstream ifs;
        ifs.open(argv[1]);
        if (ifs) {
            ifs >> n;
            if (n > 0) {
                int *arr = new int[n];
                if (arr == NULL) {
                    cerr << "Cannot allocate memory" << endl;
                    return 2;
                }
                for (size_t i = 0; i < n; ++i) ifs >> arr[i];
                process_array(arr, n);
                delete[] arr;
            } else {
                cerr << "Array is empty" << endl;
                return 3;
            }
        } else {
            cerr << "No input file" << endl;
            return 0;
        }
    }
}

