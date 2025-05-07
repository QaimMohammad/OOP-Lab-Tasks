#include <iostream>
using namespace std;

void* addToEachElement(void* arr, int size) {
    int* intArr = static_cast<int*>(arr); // cast void* to int*

    for (int i = 0; i < size; i++) {
        intArr[i] += 5; // add 5 to each element
    }

    return arr; // returning the same array
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Please provide the array elements as command-line arguments." << endl;
        return 1;
    }

    int n = argc - 1; // number of elements in the array
    int* arr = new int[n];

    // Converting arguments to integers and storing them in the array
    for (int i = 0; i < n; i++) {
        arr[i] = atoi(argv[i + 1]);
    }

    // Modifying the array
    addToEachElement(static_cast<void*>(arr), n);

    // Printing the modified array
    cout << "Modified Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // freeing dynamically allocated memory
    return 0;
}

