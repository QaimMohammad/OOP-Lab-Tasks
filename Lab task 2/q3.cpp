#include <iostream>
using namespace std;

int* resizeArray(int* arr, int &size, int newSize) {
    int* newArr = new int[newSize];

    // Copy old array elements to the new array
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }

    // Delete the old array
    delete[] arr;

    // Update size
    size = newSize;
    
    return newArr;
}

int main() {
    int size = 5;
    int* arr = new int[size];
    int count = 0;

    // Adding elements to the array
    while (count < 10) { // We try to add 10 elements
        if (count >= size) {
            arr = resizeArray(arr, size, size * 2); // Resize array if count exceeds size
        }
        cout << "Enter element " << count + 1 << ": ";
        cin >> arr[count];
        count++;
    }

    // After resizing
    cout << "Array after resizing: ";
    for (int i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // freeing dynamically allocated memory
    return 0;
}

