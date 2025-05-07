#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide the array elements as command-line arguments." << endl;
        return 1;
    }

    int n = argc - 1; // number of elements in the array
    int *arr = new int[n];

    // Converting arguments to integers and storing them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]); // atoi converts the argument to integer
    }

    int sum = 0;
    int *ptr = arr;

    // Calculating sum using pointer
    for (int i = 0; i < n; i++) {
        sum += *(ptr + i);
    }

    cout << "The sum of the array elements is: " << sum << endl;

    delete[] arr; // freeing dynamically allocated memory
    return 0;
}

